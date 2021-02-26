#include <iostream>

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s)     // A utility function to print an array of size n 
{
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
void InsertionSort(int A[], int n)    /*function for insertion Sorting , here A is the array to be sorted  , n is the size of the array */
{
    for (int i=1; i<n; i++){
        int j = i-1;
        int x = A[i];
        while (j>-1 && A[j] > x)     /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}
 
int main() 
{
 
    int A[] = {121,32,434,565,5767,7654,56567};  //predifined array
    Print(A, sizeof(A)/sizeof(A[0]), "       A");   //printing unsorted Array
 
    InsertionSort(A, sizeof(A)/sizeof(A[0])); //calling insertion sort
    Print(A, sizeof(A)/sizeof(A[0]), "Sorted A"); //printing sorted Array
 
    return 0;
}
