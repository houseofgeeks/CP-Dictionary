#include<bits/stdc++.h>
using namespace std;

/*
The Fibonacci Sequence is the series of numbers:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

The next number is found by adding up the two numbers before it.
*/
// Returns the nth fibonacci number.
long fibo(int n) {

	long a = 0;
	long b = 1;

	if (n == 0 || n == 1) {
		return n;
	}

	long c;

	for (int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

int main() {

	int n = 8;
	cout << fibo(n);
}
