/*
The Fibonacci Sequence is the series of numbers:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

The next number is found by adding up the two numbers before it.
*/

#include<bits/stdc++.h>
using namespace std;

// Calculating nth Fibonacci number using Binet's Formula.
int fib(int n) { 
double phi = (1 + sqrt(5)) / 2; 
return round(pow(phi, n) / sqrt(5)); 
} 
 
int main () 
{ 
int n = 8; 
cout << fib(n) << endl; 
return 0; 
} 

