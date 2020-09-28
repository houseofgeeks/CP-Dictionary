//Tabulation method of longest common subsequence

#include <bits/stdc++.h>
using namespace std;

// Function to return the longest common susequence
int lcs ( string str1 , string str2 , int n , int m){
    
    int i,j;
    
    int dp[n+1][m+1];// Declaring matrix of (n+1)*(m+1)
    
    
    //Initializing the matrix
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            if(i==0||j==0)
                dp[i][j]=0;
                
    
    //Filling the matrix using the modified verision of the recursive code
    
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(str1[i-1]==str2[j-1])
        dp[i][j]=dp[i-1][j-1]+1;
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        
    
    //The answer will always be stored in the last cell of the matrix
    return dp[n][m];
}

int main() {
    
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
      int m,n;
      string str1,str2;
      
      cin>>str1>>str2;
      
      n=str1.length();
      m=str2.length();
      
      cout<<lcs(str1,str2,n,m)<<endl;	
}
