#include <bits/stdc++.h>
using namespace std;
int gcd(int m,int n)
{
    if(m==0)
        return n;
    return gcd(n%m,m);
}
int totient(int n)
{
    if(n<=0)
        return 0;
    int ret=1;
    for(int i=2;i<n;i++)
    {
        if(gcd(i,n)==1)//finding numbers of gcd 1 with given number
            ret++;
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    cout<<totient(n)<<"\n";
    return 0;
}
