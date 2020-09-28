#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 +7; // Mostly commonly used prime in CP

// return x^y in logn
int power(int x, int y){
    if(y == 0)
        return 1;
    // if y is odd
    if(y&1){
        return x * power(x, y -1) % MOD;
    }
    // stores temprory value much like DP
    long long temp = power(x, y/2);

    return temp * temp % MOD;
}

int modulo_inverse(int num){
    // modulo inverse of a num with MOD is nothing but num^(MOD -2)
    int result = power(num, MOD -2);
    return result;
}

int main(){
    int num = 101; //some random number
    int res = modulo_inverse(num);
    cout << res << endl;
}