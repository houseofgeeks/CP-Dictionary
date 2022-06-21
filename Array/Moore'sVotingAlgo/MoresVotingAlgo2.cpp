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

vector<int> mooreVotingAlgo(int arr[],int n){
    int mostFrequent=-1;
    int countMostFrequent=0;
    int secondMostFrequent=-1;
    int countSecondMostFrequent=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==mostFrequent){
            countMostFrequent++;
        }
        else if(arr[i]==secondMostFrequent){
            countSecondMostFrequent++;
        }
        else if(countMostFrequent==0){
            mostFrequent=arr[i];
            countMostFrequent++;
        }
        else if(countSecondMostFrequent==0){
            secondMostFrequent=arr[i];
            countSecondMostFrequent++;
        }
        else{
            countMostFrequent--;
            countSecondMostFrequent--;
        }
    }
    vector<int> ans;
    int freq1=getFreq(arr,n,mostFrequent);
    int freq2=getFreq(arr,n,secondMostFrequent);
    if(freq1>(n/3)){
        ans.push_back(mostFrequent);
    }
    if(freq2>(n/3)){
        ans.push_back(secondMostFrequent);
    }
    return ans;
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans;
    ans=mooreVotingAlgo(arr,n);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}