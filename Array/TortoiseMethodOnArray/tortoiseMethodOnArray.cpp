#include<bits/stdc++.h>
using namespace std;

//TASK==>>  Find duplicate in an array of n+1 integers and array is not sorted

/// Tortoise method is a method to find loop in linked list using slow and fast pointer 
// where slow point moves one step at a time whereas fast pointer moves 2 steps at a time 

int tortoise(int arr[],int n){
    int fast=arr[0];
    int slow=arr[0];
    do{
        fast=arr[arr[fast]];
        slow=arr[slow];
    }while(fast!=slow);

    fast=arr[0];
    while(fast!=slow){
        fast=arr[fast];
        slow=arr[slow];
    }
    return fast;
}

int main(){
    int n;cin>>n;
    int arr[n+1];
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    cout<<tortoise(arr,n)<<endl;
    return 0;
}