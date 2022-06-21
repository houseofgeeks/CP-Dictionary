#include<bits/stdc++.h>
using namespace std;

int getFreq(int arr[],int n,int mostFreq){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==mostFreq){
            count++;
        }
    }
    return count;
}
int mooreVotingAlgo(int arr[],int n){
    int mostFrequent=0;
    int countMostFrequent=0;
    for(int i=0;i<n;i++){
        if(countMostFrequent==0){
            mostFrequent=arr[i];
        }
        
        if(arr[i]==mostFrequent){
            countMostFrequent++;
        }
        else{
            countMostFrequent--;
        }
    }
    
    int freq=getFreq(arr,n,mostFrequent);
    
    if(freq>(n/2)){
        return mostFrequent;
    }else{
        return -1;
    }
}
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<mooreVotingAlgo(arr,n)<<endl;
    return 0;
}