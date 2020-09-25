#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int r)
{
    int  p = a[r];
    int  k = l-1;
    for(int i= l;i<r;i++)
    {
        if(a[i]<p)
        {
            k++;
            swap(a[k],a[i]);
        }
    }
    swap(a[k+1],a[r]);
    return k+1;
}
void quick(int a[],int l ,int r)
{
    if(l<=r)
    {
        int p = partition(a,l,r);
        quick(a,l,p-1);
        quick(a,p+1,r);
    }
}
int main()
{
    int a[5] = {1,2,5,3,4};
    quick(a,0,5);
    for (auto i:a)
    {
        cout<<i<<" ";
    }
    return 0;
}
