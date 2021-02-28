//Recursive approach of Lowest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

// Function to return the longest common susequence
int lcs ( string str1 , string str2 , int n , int m){
    
    //Base Cases
    if(n==0||m==0)
    return 0;
    
    //If the current character matches
    if(str1[n-1]==str2[m-1])
    return 1+lcs(str1,str2,n-1,m-1);
    
    
    //If the current character does not matches
    return max(lcs(str1,str2,n-1,m),lcs(str1,str2,n,m-1));
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
