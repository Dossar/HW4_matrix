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

    int m1rows = 3, m1cols = 3, m2rows = 3, m2cols = 3;
    int i, j, k;
    int sum = 0;
    int diff = 0;
    int diagvalue;
    
    // Initialize our test matrices.
    int zeroMatrix[m1cols][m1cols];
    int diagMatrix[m1cols][m1cols];
    int matrix1[m1rows][m1cols], matrix2[m2rows][m2cols];
    int prodMatrix1[m1rows][m2cols]; // Result from multiplication
    int addMatrix1[m1rows][m1cols]; // Result from addition
    int subMatrix1[m1rows][m1cols]; // Result from addition
    
    
    // CREATE ZERO MATRIX
    for (i = 0; i < 3 ; i++) {
        for (j = 0; j < 3 ; j++)
            zeroMatrix[i][j] = 0;
    }     
    
    cout << "Zero Matrix:" << endl;
    for (i = 0; i < 3 ; i++) {
        for (j = 0; j < 3 ; j++) {
            cout << zeroMatrix[i][j] << " ";
        }
        cout << endl; // Newline for next row
    }
    cout << "\n";
    // END CREATE ZERO MATRIX
    
    
    // CREATE DIAGONAL MATRIX
    cout << "Enter value you want in your diagonal:" << endl;
    cin >> diagvalue;
    cout << "\n";
    
    for (i = 0; i < 3 ; i++) {
        // Initialize entire row to zero first, then insert number into diagonal.
        for (j = 0; j < 3 ; j++)
            diagMatrix[i][j] = 0;
        j = 0; // Reinitialize j to zero so we can get the correct column in the diagonal
        j += i;
        diagMatrix[i][j] = diagvalue;
    }     
    
    cout << "Diagonal Matrix:" << endl;
    for (i = 0; i < 3 ; i++) {
        for (j = 0; j < 3 ; j++) {
            cout << diagMatrix[i][j] << " ";
        }
        cout << endl; // Newline for next row
    }
    cout << "\n";
    // END CREATE DIAGONAL MATRIX    
    
    
    // INPUT MATRICES
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
    
    // Print out our two matrices to see they were input correctly
    cout << "Matrix 1:" << endl;
    for (i = 0; i < m1rows; i++) {
        for (j = 0; j < m1cols; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl; // Newline for next row
    }
    cout << "\n";
    
    cout << "Matrix 2:" << endl;
    for (i = 0; i < m2rows; i++) {
        for (j = 0; j < m2cols; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl; // Newline for next row
    }
    cout << "\n";
    // END OF INPUT MATRICES

    
    // MATRIX MULTIPLICATION
    // For each row of matrix1 and for each column of matrix2, multiply the matrices.
    for (i = 0; i < m1rows; i++) {
        for (j = 0; j < m2cols; j++) {
            sum = 0;
            // We traverse down the rows of said column in matrix 2 to get the sum for the product matrix.
            for (k = 0; k < m2rows; k++)
                sum += matrix1[i][k] * matrix2[k][j];
            prodMatrix1[i][j] = sum;
        }
    }

    // Print out the matrix.
    cout << "Resulting product matrix is " << m1rows << "x" << m2cols <<"." << endl;
    for (i = 0; i < m1rows; i++) {
        for (j = 0; j < m2cols; j++) {
            cout << prodMatrix1[i][j] << " ";
        }
        cout << endl; // Newline for next row
    }
    cout << "\n";
    // END OF MATRIX MULTIPLICATION
    
    
    // MATRIX ADDITION
    for (i = 0; i < m1rows; i++) {
        for (j = 0; j < m1cols; j++){
            sum = matrix1[i][j] + matrix2[i][j];
            addMatrix1[i][j] = sum;
        }
    }
    
    cout << "Matrix 1 + Matrix 2 gave:" << endl;
    for (i = 0; i < m1rows; i++) {
        for (j = 0; j < m1cols; j++) {
            cout << addMatrix1[i][j] << " ";
        }
        cout << endl; // Newline for next row
    }
    cout << "\n";
    // END OF MATRIX ADDITION
    
    
    // MATRIX SUBTRACTION
    for (i = 0; i < m1rows; i++) { 
        for (j = 0; j < m1cols; j++){
            diff = matrix1[i][j] - matrix2[i][j];
            subMatrix1[i][j] = diff;
        }
    }
    
    cout << "Matrix 1 - Matrix 2 gave:" << endl;
    for (i = 0; i < m1rows; i++) {
        for (j = 0; j < m1cols; j++) {
            cout << subMatrix1[i][j] << " ";
        }
        cout << endl; // Newline for next row
    }
    // END OF MATRIX SUBTRACTION
    
    
    /*
     The follow block of code was originally for scanning in dimensions. We don't need this right now.
     */
    
//    // Enter in the dimensions of our two matrices.
//    cout << "Enter dimensions of your two matrices to multiply." << endl;
//    cout << "Remember the columns of 1st matrix need to match rows of 2nd matrix." << endl;
//    cout << "Matrix 1 rows: ";
//    cin >> m1rows; // Rows of matrix1
//    cout << "Matrix 1 columns: ";
//    cin >> m1cols; // Columns of matrix1
//    cout << "Matrix 2 rows: ";
//    cin >> m2rows; // Rows of matrix2
//    cout << "Matrix 2 columns: ";
//    cin >> m2cols; // Columns of matrix
//    int matrix1[m1rows][m1cols], matrix2[m2rows][m2cols];
//    int prodMatrix1[m1rows][m2cols]; // Result from multiplication
//    int addMatrix1[m1rows][m1cols]; // Result from addition
//    int subMatrix1[m1rows][m1cols]; // Result from addition
//    cout << endl;
//
//     
    
    return 0;
}

