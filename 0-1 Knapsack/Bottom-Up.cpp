//Tabulation form of 0-1 Knapsack

#include <bits/stdc++.h>
using namespace std;



// Function to return the maimum profit
int knapsack ( int *wt , int *value , int n , int cap){
    
    int i,j;
    
    int dp[n+1][cap+1];// Declaring matrix of (size+1)*(capacity+1)
    
    
    //Initializing the matrix
    for(i=0;i<=n;i++)
        for(j=0;j<=cap;j++)
            if(i==0||j==0)
                dp[i][j]=0;
                
    
    //Filling the matrix using the modified verision of the recursive code
    
    for(i=1;i<=n;i++)
    for(j=1;j<=cap;j++)
        if(wt[i-1]<=j)
        dp[i][j]=max(dp[i-1][j],value[i-1]+dp[i-1][j-wt[i-1]]);
        else
        dp[i][j]=dp[i-1][j];
        
    
    //The answer will always be stored in the last cell of the matrix
    return dp[n][cap];
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
