#include<bits/stdc++.h>
using namespace std;
void selection(int *a,int n)
{
    int k;
    for(int i=0;i<n;i++)
    {
        int f=0;                     //flag
        int mi = a[i];               //intializing min value 
        for(int j=i;j<n;j++)
        {
            if(a[j]<mi)
            {
                mi=a[j];            //finding the min value
                k=j;
                f=1;                //assigning the flag value to 1
            }
        }
        if(f==1)
        {
            a[k]=a[i];               //exchanging the vlaues 
            a[i]=mi;				 // assigning the min value to the starting indexes
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int *a;
    a = new int[n];
 	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }   
    selection(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return  0; 
}
