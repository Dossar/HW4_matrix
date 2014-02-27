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

class Matrix
{
public:
    Matrix(); // Default constructor
    Matrix(int diagvalue); // Constructor with parameters
    Matrix(const Matrix& M); // Copy constructor
    ~Matrix(); // Destructor
    void inputMat();
    //void printMat();
    friend ostream& operator <<(ostream& out, const Matrix& Mat);
    friend Matrix operator *(const Matrix& Mat1, const Matrix& Mat2);
    friend Matrix operator +(const Matrix& Mat1, const Matrix& Mat2);
    friend Matrix operator -(const Matrix& Mat1);
    friend Matrix operator -(const Matrix& Mat1, const Matrix& Mat2);
    friend bool operator ==(const Matrix& Mat1, const Matrix& Mat2);
    friend istream& operator >>(istream& in, Matrix& Mat);
    
private:
    int data[3][3];
    
};

// Default constructor. Creates zero matrix.
Matrix::Matrix()
{
    int i, j;
    for (i = 0; i < 3 ; i++) {
        for (j = 0; j < 3 ; j++)
            data[i][j] = 0;
    }
   
}

// Constructor with parameters. Creates diagonal matrix.
Matrix::Matrix(int diagvalue)
{
    int i, j;

    for (i = 0; i < 3; i++) {
        // Initialize entire row to zero first, then insert number into diagonal.
        for (j = 0; j < 3; j++)
            data[i][j] = 0;
        j = 0; // Reinitialize j to zero so we can get the correct column in the diagonal
        j += i;
        data[i][j] = diagvalue;
    }

}

// Copy constructor
Matrix::Matrix(const Matrix& M)
{
    int i, j;
    for (i = 0; i < 3 ; i++) {
        for (j = 0; j < 3 ; j++)
            data[i][j] = M.data[i][j]; // Copy elements from our referenced matrix into our new matrix.
    }
    
}

// Destructor
Matrix::~Matrix()
{
        //cout << "A matrix has been destroyed." << endl;
}


// Make fin a global variable so we can save our position in our input file.
ifstream fin("file.txt");

// Overloaded input operator
istream& operator >>(istream& in, Matrix& Mat){
    
    int i, j;
    
    // Read in 9 elements from our file.
    for( i = 0 ; i < 3 ; i++ ){
        for( j = 0 ; j < 3 ; j++ ){
            // fin ignores whitespace and newlines
            // We also keep our position in the file with fin
            fin >> Mat.data[i][j];
        }
    }
    
    return in;
    
}

// Overloaded output operator
ostream& operator <<(ostream& out, const Matrix& Mat){
    
    int i, j;
    //cout << "Matrix:" << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            out << Mat.data[i][j] << " ";
        }
        out << endl; // Newline for next row
    }
    out << "\n";
    
}

// Overloaded multiplication operator
Matrix operator *(const Matrix& Mat1, const Matrix& Mat2){
    
    Matrix multMat;
    int sum = 0;
    int i, j, k;
    // For each row of matrix1 and for each column of matrix2, multiply the matrices.
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum = 0;
            // We traverse down the rows of said column in matrix 2 to get the sum for the product matrix.
            for (k = 0; k < 3; k++)
                sum += Mat1.data[i][k] * Mat2.data[k][j];
            multMat.data[i][j] = sum;
        }
    }
    return multMat;
    
}

// Overloaded addition operator
Matrix operator +(const Matrix& Mat1, const Matrix& Mat2){
    
    Matrix addMat;
    int sum = 0;
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++){
            sum = Mat1.data[i][j] + Mat2.data[i][j];
            addMat.data[i][j] = sum;
        }
    }
    return addMat;
    
}

// Overloaded binary minus (subtraction) operator
Matrix operator -(const Matrix& Mat1, const Matrix& Mat2){
    
    Matrix subMat;
    int diff = 0;
    int i, j;
    for (i = 0; i < 3; i++) { 
        for (j = 0; j < 3; j++){
            diff = Mat1.data[i][j] - Mat2.data[i][j];
            subMat.data[i][j] = diff;
        }
    }
    return subMat;
    
}

// Overloaded unary minus operator
Matrix operator -(const Matrix& Mat1){
    
    Matrix minusMat;
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            minusMat.data[i][j] = (Mat1.data[i][j])*(-1);
    }
    return minusMat;
    
}

// Overloaded equality operator
bool operator ==(const Matrix& Mat1, const Matrix& Mat2){
    
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++){
            if( Mat1.data[i][j] != Mat2.data[i][j] ){
                return false;
            }
        }
    }
    return true;
    
}


int main() {

    // Z is zero matrix.
    Matrix Z;
    cout << "Matrix Z:" << endl;
    cout << Z;
    
    // D is 2 diagonal, E is 1 diagonal.
    Matrix D(2);
    cout << "Matrix D:" << endl;
    cout << D;
    Matrix E(1);
    cout << "Matrix E:" << endl;
    cout << E;
    
    // A and C are the input file matrices. Initialize to zero first, then input stuff.
    Matrix A;
    Matrix C;
    cin >> A; // input works.
    cin >> C; // input works.
    cout << "Matrix A:" << endl;
    cout << A;
    cout << "Matrix C:" << endl;
    cout << C;
    fin.close(); // We are now done with our input file, so close it.
    
    // B is a copy of A.
    Matrix B(A);
    cout << "Matrix B:" << endl;
    cout << B;
    
    // Test mult and add functions.
    // output works.
    cout << A*B; // mult works.
    cout << A+B; // add works.
    cout << -A; // unary - works.
    cout << A-B; // binary - works.
    if( A==B )
        cout << "Both Matrices are the same." << endl; // equality works.
    
    
    return 0;
}

