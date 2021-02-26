#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
    if (n <= 1)
        cout << " No prime numbers below " << n << endl;
    else
    {
        bool prime[n + 1]; // first we initialize a array of length n+1
        for (int i = 0; i < n + 1; i++)
            prime[i] = true; // store true everywhere

        for (int k = 2; k * k <= n; k++)
        {
            if (prime[k] == true)
            {
                for (int i = k * k; i <= n; i += k) // now we convert all multiples of p as false indicating they are not prime
                    prime[i] = false;
            }
        }

        // Printing all prime numbers
        for (int p = 2; p <= n; p++)
            if (prime[p])
                cout << p << " ";
    }
}

int main()
{
    int n = 100;
    cout << "All prime numbers before " << n << " are :";
    SieveOfEratosthenes(n);
    return 0;
}
