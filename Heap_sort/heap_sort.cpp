#include<bits/stdc++.h>
using namespace std;

void heap_sort(int arr[], int n){
    // initialising the heap that is max_heap by default
    priority_queue<int> q;
    for(int i = 0; i < n; ++i){
        //filling the heap
        q.push(arr[i]);
    }
    for(int i = 0; i < n; ++i){
        //sorting the the arr using heap
        arr[n - i -1] = q.top();
        q.pop();
    }
    return;
}

int main(){
    int n = 10;
    int arr[] = {10, 8, 9, 7, 1, 3, 2, 5, 4, 6};

    //main heap sort function
    heap_sort(arr, n);
    
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}