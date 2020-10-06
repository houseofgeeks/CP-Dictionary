#include <bits/stdc++.h>
using namespace std;

//for getting sum of the numbers till index specified
int getSum(int BITree[],int index) {

   int sum=0;
   while(index>0) {

      sum+=BITree[index];
      //index & (-index) gives us the last set bit(i.e. the last 1)
      index -= index & (-index); //It gives parent of an index by subtracting last set bit
   }
   return sum;

}

//For updating the BIT by changing the value at specified index
void update_BITree(int BITree[],int n,int index,int value) {

  while(index<=n) {
     BITree[index] += value;
    index += index & (-index); //We make changes on all the index we get after adding the last set bit

  }

}

//It is to convert the numbers in the array in its relative order
void convert(int arr[],int n) {

   int temp[n];
   for(int i=0;i<n;i++)
    temp[i]=arr[i]; //Making a copy of array

   sort(temp,temp+n);//Sorting the copy array

   for(int i=0;i<n;i++) {

        //This changes the array element with its respective relative order , such as an arr = {-9,10,5}
        // becomes arr={1,3,2} (i.e. replaces the nos. with its index numbers in sorted copy array +1)
        //This enables us to also handle negative numbers
        arr[i] = lower_bound(temp,temp+n,arr[i]) - temp +1;
   }
}

int inversion_count(int arr[],int n) {

   int inver_count =0; //Initialise the counter

   convert(arr,n);//This converts the array

   int BITree[n+1]; // Create a BIT using the values of arr as index for the BIT
   for(int i=0;i<=n;i++) {
      BITree[i] = 0;
   }

   for(int i=n-1;i>=0;i--) {
       //We traverse the array backwards and count the numbers of indexes smaller than the number
       //by using getSum() of BIT

       inver_count += getSum(BITree,arr[i]-1);
       update_BITree(BITree,n,arr[i],1); //Then keep updating the BIT as we move forward

   }

   return inver_count;
}

int main() {

  int arr[]={8,4,2,-6};
  int n= sizeof(arr)/sizeof(arr[0]);
  int result = inversion_count(arr,n);
  cout<<result<<endl;

  return 0;
}








