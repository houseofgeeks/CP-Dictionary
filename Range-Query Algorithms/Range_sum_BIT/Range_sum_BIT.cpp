#include<bits/stdc++.h>
using namespace std;

// Builds and updates the Tree, BIT is the tree
// pos is index to be updated
// delta is the amount to be added
void update(vector<int> &BIT, int pos, int delta, int n){
    for(int i = pos; i <= n; i += i&-i){
        BIT[i] += delta;
    }
    return;
}

//Queries prefix sum
// pos is ind upto which sum is required
int query(vector<int> BIT, int pos){
    int accumulaor = 0;
    for(int i = pos; i > 0; i -= i&-i){
        accumulaor += BIT[i];
    }
    return accumulaor;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int n = 10;
    int arr[] = {-1, 10, 1, 13, 5, 7, 9, 7, 12, 19, 10};

    //initialising the tree with 0
    vector<int> BIT(n +1, 0);

    for(int i = 1; i <= n; ++i){
        update(BIT, i, arr[i], n);
    }

    cout << query(BIT, 3) << endl;

}