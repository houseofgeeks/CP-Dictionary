#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int r)
{
    int  p = a[r];                       //assigning the initial index
    int  k = l-1;						//assigning the max index 
    for(int i= l;i<r;i++)
    {
        if(a[i]<p)						//searching for min value 
        {						
            k++;
            swap(a[k],a[i]);			//swapping with the proper element
        }
    }
    swap(a[k+1],a[r]);					//element to be swapped with a[r] 
    return k+1;
}
void quick(int a[],int l ,int r)        //function to call recursively the quick sort algo
{
    if(l<=r)
    {
        int p = partition(a,l,r);		//calling the partition function recursively to find the partition index
        quick(a,l,p-1);					//sorting the first half recursively 
        quick(a,p+1,r);					//sortng the second half recursively 
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
