#include<bits/stdc++.h>
using namespace std;
double median_of_two_sorted_arrays(int arr1[],int arr2[],int n,int m){
    int l=0,h=n; //considering n<=m
    while(l<=h){
        int i1=(l+h)/2;
        int i2=(n+m+1)/2 -i1; 
        int min1 = (i1==n)? INT_MAX: arr1[i1];
        int min2 = (i2==m)? INT_MAX: arr2[i2];
        int max1 = (i1==0)? INT_MIN: arr1[i1-1];
        int max2 = (i2==0)? INT_MIN: arr2[i2-1];
        if(max1<=min2 && max2<=min1){ //found correct partition in both halves
            if((n+m)%2==0){
                return ((double)max(max1,max2)+min(min1,min2))/2;    
            }
            else{
                return (double)max(max1,max2);
            }
        }
        else if(max1>min2){
            h=i1-1;
        }
        else{
            l=i1+1;
        }
    }
}
int main(){
    int arr1[5]={10,20,30,40,50};
    int arr2[9]={5,15,25,35,45,55,65,75,85};
    cout<<median_of_two_sorted_arrays(arr1,arr2,5,9);
    return 0;
}