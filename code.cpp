
#include <bits/stdc++.h>
using namespace std;

// Returns repeating sequence of a fraction.
// If repeating sequence doesn't exits,
// then returns -1
string fractionToDecimal(int numerator, int denominator)
{
    string res;

    /* Create a map to store already seen remainders
       remainder is used as key and its position in
       result is stored as value. Note that we need
       position for cases like 1/6. In this case,
       the recurring sequence doesn't start from first
       remainder. */
    map<int, int> mp;
    mp.clear();

    // Find first remainder
    int rem = numerator % denominator;

    // Keep finding remainder until either remainder
    // becomes 0 or repeats
    while ((rem != 0) && (mp.find(rem) == mp.end()))
    {
        // Store this remainder
        mp[rem] = res.length();

        // Multiply remainder with 10
        rem = rem * 10;

        // Append rem / denr to result
        int res_part = rem / denominator;
        res += to_string(res_part);

        // Update remainder
        rem = rem % denominator;
    }
    return (rem == 0) ? "-1" : res.substr(mp[rem]);
}

// Checks whether a number is prime or not
bool isPrime(int n)
{
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
   return true;
}

// If all conditions are met,
// it proves Midy's theorem
void Midys(string str, int n)
{
    int l = str.length();
    int part1 = 0, part2 = 0;
    if (!isPrime(n))
    {
        cout << "Denominator is not prime, "
             << "thus Midy's theorem is not applicable";
    }
    else if (l % 2 == 0)
    {
        for (int i = 0; i < l / 2; i++)
        {
            part1 = part1 * 10 + (str[i] - '0');
            part2 = part2 * 10 + (str[l / 2 + i] - '0');
        }
        cout << part1 << " + " << part2 << " = "
             << (part1 + part2) << endl;
        cout << "Midy's theorem holds!";
    }
    else
    {
        cout << "The repeating decimal is of odd length "
             << "thus Midy's theorem is not applicable";
    }
}

// Driver code
int main()
{
    int numr = 2, denr = 11;
    string res = fractionToDecimal(numr, denr);
    if (res == "-1")
        cout << "The fraction does not have repeating decimal";
    else {
        cout << "Repeating decimal = " << res << endl;
        Midys(res, denr);
    }
    return 0;
}
