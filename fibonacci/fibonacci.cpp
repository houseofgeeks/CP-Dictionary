/*
The Fibonacci Sequence is the series of numbers:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

The next number is found by adding up the two numbers before it.
*/

// Code to find Nth Fibonacci number using matrix 
// exponentiation method, having time complexity of O(logN)

#include<bits/stdc++.h>
using namespace std;

// Helper method to perform matrix multiplication and
// store the result in F[][].
void multiply(int F[2][2], int M[2][2]) {
   int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
   int b= F[0][0] * M[0][1] + F[0][1] * M[1][1];
   int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
   int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
   F[0][0] = a;
   F[0][1] = b;
   F[1][0] = c;
   F[1][1] = d;
}

// Helper method to raise the matrix F[][] 
// to the power of n.
// [Note: This method is designed specifically 
// for finding nth fibonacci number and may not 
// be used as a general method.]
void power(int F[2][2], int n) {
   if (n == 0 || n == 1)
      return;
   int M[2][2] = {{1,1},{1,0}};
   power(F, n / 2);
   multiply(F, F);
   if (n % 2 != 0)
      multiply(F, M);
}

// Method to return the nth fibonacci number 
// using other helper methods.
int fibonacci_matrix(int n) {
   int F[2][2] = {{1,1},{1,0}};
   if (n == 0)
      return 0;
   power(F, n - 1);
   return F[0][0];
}
int main() {
   
   int n = 8;
   cout<<fibonacci_matrix(n)<<endl;

   return 0;
}