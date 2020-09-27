Approach for Median of two sorted arrays in O(LogN) where N is the size of array (A) with lesser elements.
Let M be the size of the other array (B).
A={10,20,30,40,50} N=5
B={5,15,25,27,28,55,65,75,85} M=9
Idea is to consider two halves -left and right- which will contain equal number of elements in every iteration (if there are odd number of elements left half can contain one extra element)
Left -> A[0,...,i1-1] B[0,....,i2-1]
Right-> A[i1,....N-1] B[i2,....,M-1]
where i1 points to an element in and i2 is calculated using the formula -> i2=(N+M+1)/2 -i1 to maintain equal number of elements in both the halves

We start our binary search in array A
i1=(l+h)/2 and i2 is calculated using the formula above.
For the example above i1=2 , i2=(14+1)/2 -2 =5
Case 1: All elements in left half are smaller than or equal to all elements in right half:
 in this case we have found our median 
 for even no of elements (example here 14)
 Median = (max(A[i1-1],B[i2-1])+min(A[i1],B[i2]))/2
        = (max(20,28)+min(30,55))/2 = (28+30)/2 = 29
 for odd no of elements
 Median = max(A[i1-1],B[i2-1]);
Case 2: When A[i1] is in right half but should have been in left half to find the median 
(eg: if B was {5,15,25,35,45,55,65,75,85} 30 would be in right half but should have been in left half as it is less than 35,45)
in this case we continue our BS in the right half of A

case 3: When A[i1] is in left half but should have been in right half, we continue our BS in the left half of A