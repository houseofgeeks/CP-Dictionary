
Recursive approach for 0-1 Knapsack


#include <bits/stdc++.h>
using namespace std;



// Function to return the maimum profit
int knapsack ( int *wt , int *value , int n , int cap){
    
    
    //Base condtions
    if( n<=0  || cap<=0)
    return 0;
    
    
    /* A particular object might get selected in the knapsack
       only if it's weight is less than the capacity of knapsack*/
       
    if(wt[n-1]<=cap)
    return max( knapsack(wt,value,n-1,cap) , value[n-1] + knapsack(wt,value,n-1,cap-wt[n-1]));
    
    
    return  knapsack(wt,value,n-1,cap);
 
 
 
}

int main() {
    
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
    
      int cap,i,n;
      
      cin>>n;
      
      int wt[n],value[n];
      
      for(i=0;i<n;i++)
         cin>>wt[i];
      
       for(i=0;i<n;i++)
         cin>>value[i];
      
      cin>>cap;
      
      
      cout<< knapsack(wt , value , n ,cap)<<endl;
  
	
}










