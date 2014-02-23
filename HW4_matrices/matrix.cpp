/* 
 * File:   main.cpp
 * Author: Roy Van Liew and Saqib Zahid
 *
 * Created on February 21, 2014, 12:13 PM
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*
 * 
 */
int main() {

    int m1rows, m1cols, m2rows, m2cols;
    int i, j, k;
    int sum = 0;

    // Enter in the dimensions of our two matrices.
    cout << "Enter dimensions of your two matrices to multiply." << endl;
    cout << "Remember the columns of 1st matrix need to match rows of 2nd matrix." << endl;
    cout << "Matrix 1 rows: ";
    cin >> m1rows; // Rows of matrix1
    cout << "Matrix 1 columns: ";
    cin >> m1cols; // Columns of matrix1
    cout << "Matrix 2 rows: ";
    cin >> m2rows; // Rows of matrix2
    cout << "Matrix 2 columns: ";
    cin >> m2cols; // Columns of matrix
    int matrix1[m1rows][m1cols], matrix2[m2rows][m2cols];
    int prodMatrix1[m1rows][m2cols];
    cout << endl;

    cout << "Input numbers for matrix 1." << endl;
    for (i = 0; i < m1rows; i++) {
        cout << "Row " << i+1 << ", enter " << m1cols << " numbers:" << endl;
        for (j = 0; j < m1cols; j++) {
            cin >> matrix1[i][j];
        }
    }
    cout << endl;

    cout << "Input numbers for matrix 2." << endl;
    for (i = 0; i < m2rows; i++) {
        cout << "Row " << i+1 << ", enter " << m2cols << " numbers:" << endl;
        for (j = 0; j < m2cols; j++) {
            cin >> matrix2[i][j];
        }
    }
    cout << endl;

    // For each row of matrix1 and for each column of matrix2, multiply the matrices.
    for (i = 0; i < m1rows; i++) {
        for (j = 0; j < m2cols; j++) {
            sum = 0.0;
            for (k = 0; k < m2rows; k++)
            // We traverse down the rows of said column in matrix 2 to get the sum for the product matrix.
                sum += matrix1[i][k] * matrix2[k][j];
            prodMatrix1[i][j] = sum;
        }
    }

    // Print out the matrix.
    cout << "Resulting matrix is " << m1rows << "x" << m2cols <<"." << endl;
    for (i = 0; i < m1rows; i++) {
        for (j = 0; j < m2cols; j++) {
            cout << prodMatrix1[i][j] << " ";
        }
        cout << endl; // Newline for next row
    }
    
    return 0;
}

