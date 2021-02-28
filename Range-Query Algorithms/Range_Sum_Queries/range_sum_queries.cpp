#include<bits/stdc++.h>
using namespace std;
void updateValue(int *segtree, int ss, int se, int i, int diff, int si)  
{  
    // Base Case: If the input index lies outside the range of this segment  
    if (i < ss || i > se)  
        return;  
    // If the input index is in range of this node, then update the value of the node and its children  
    segtree[si] = segtree[si] + diff;  
    if (se > ss)  
    {  
        int mid = (ss+se)/2;  
        updateValue(segtree, ss, mid, i, diff, 2*si + 1);  
        updateValue(segtree, mid+1, se, i, diff, 2*si + 2);  
    }  
}  
void updateValue(int arr[], int *segtree, int n, int i, int new_val)  
{  
    // Check for invalid index
    if (i < 0 || i > n-1)  
    {  
        cout<<"Invalid Input";  
        return;  
    }  
    int diff = new_val - arr[i];  
    arr[i] = new_val;   
    updateValue(segtree, 0, n-1, i, diff, 0);  
}  
int getSum(int *segtree, int ss, int se, int qs, int qe, int si)  
{  
    // If segment of this node is a part of given range, then return the sum of the segment  
    if (qs <= ss && qe >= se)  
        return segtree[si];  
    // If segment of this node is outside the given range  
    if (se < qs || ss > qe)  
        return 0;  
    // If a part of this segment overlaps with the given range  
    int mid = (ss+se)/2;  
    return getSum(segtree, ss, mid, qs, qe, 2*si+1) + getSum(segtree, mid+1, se, qs, qe, 2*si+2);  
}  
int getSum(int *segtree, int n, int qs, int qe)  
{  
    // Check for invalid input
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input";  
        return -1;  
    }  
    return getSum(segtree, 0, n-1, qs, qe, 0);  
}   
void constructST(int arr[], int ss, int se, int *segtree, int si)  
{  
    if (ss == se)  
    {  
        segtree[si] = arr[ss];  
        return;
    }  
    int mid = (se+ss)/2;
    constructST(arr, ss, mid, segtree, si*2+1);
    constructST(arr, mid+1, se, segtree, si*2+2);
    segtree[si] = segtree[2*si+1] + segtree[2*si+2] ;  
}  
int *constructST(int arr[], int n)  
{  
    int x = (int)(ceil(log2(n)));    
    int ms = 2*(int)pow(2, x) - 1; //maximum size 
    int *segtree = new int[ms];  
    constructST(arr, 0, n-1, segtree, 0); 
    return segtree;  
}  
int main()  
{  
    int arr[] = {1, 3, 5, 7, 9, 11};  
    int n = 6;
    int *segtree = constructST(arr, n);  
    cout<<"Sum of values in given range = "<<getSum(segtree, n, 1, 3)<<endl;  
    updateValue(arr, segtree, n, 1, 10); 
    cout<<"Updated sum of values in given range = "
            <<getSum(segtree, n, 1, 3)<<endl;  
    return 0;  
}  