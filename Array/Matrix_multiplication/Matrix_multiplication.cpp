/*
    ****** Theory *******
    To mutliply two matrices, The number of column of first matrix must be equal to the 
    number of rows of second matrix.

    For this explaination we limit the matrix size to 10.

    ****** Abbreviations ******
    Consider first matrix A[10][10] and second matrix B[10][10].
    To store the result we use result[10][10].

    row_1 and column_1 denotes row and column of first matrix
    row_2 and column_2 denotes row and column of second matrix

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[10][10], B[10][10], result[10][10], row_1, column_1, row_2, column_2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> row_1 >> column_1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> row_2 >> column_2;

    // If column of first matrix in not equal to row of second matrix,
    while (column_1 != row_2)
    {
        cout << "Error! column of first matrix should be equal to row of second matrix.";

        cout << "Enter rows and columns for first matrix: ";
        cin >> row_1 >> column_1;

        cout << "Enter rows and columns for second matrix: ";
        cin >> row_2 >> column_2;
    }

    // Storing elements of first matrix.
    cout << endl
         << "Enter elements of matrix 1:" << endl;
    for (int i = 0; i < row_1; ++i)
        for (int j = 0; j < column_1; ++j)
        {
            cout << "Enter A[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> A[i][j];
        }

    // Storing elements of second matrix.
    cout << endl
         << "Enter elements of matrix 2:" << endl;
    for (int i = 0; i < row_2; ++i)
        for (int j = 0; j < column_2; ++j)
        {
            cout << "Enter B[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> B[i][j];
        }

    // Initializing elements of matrix result to 0.
    for (int i = 0; i < row_1; ++i)
        for (int j = 0; j < column_2; ++j)
        {
            result[i][j] = 0;
        }

    // resultiplying matrix a and b and storing in array result.
    for (int i = 0; i < row_1; ++i)
        for (int j = 0; j < column_2; ++j)
            for (int k = 0; k < column_1; ++k)
            {
                result[i][j] += A[i][k] * B[k][j];
            }

    // Displaying the resultiplication of two matrix.
    cout << endl
         << "Output Matrix: " << endl;
    for (int i = 0; i < row_1; ++i)
        for (int j = 0; j < column_2; ++j)
        {
            cout << " " << result[i][j];
            if (j == column_2 - 1)
                cout << endl;
        }

    return 0;
}