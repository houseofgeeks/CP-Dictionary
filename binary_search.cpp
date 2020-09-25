#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *a;
    a= new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    int l=0,h=n-1;
    int m;
    int fl=0;
    int c=0;
    while(l<=h)
    {
        c++;
        m=l+((h-l)/2);
        if(a[m]==key)
        {
            fl=1;
            break;
        }
        else if(a[m]<key)
        {
            l=m+1;
        }
        else
        {
            h=m-1;
        }
    }
    if(fl==1)
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    cout<<c<<endl;
    return 0;
}
