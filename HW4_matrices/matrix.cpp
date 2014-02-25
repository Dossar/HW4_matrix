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
    void printMat();
    
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
        cout << "A matrix has been destroyed." << endl;
}



// Make fin a global variable so we can save our position in our input file.
ifstream fin("file.txt");

// Read in stuff from our input file into our matrices.
void Matrix::inputMat(){
    
    int i, j;
    
    // Read in 9 elements from our file.
    for( i = 0 ; i < 3 ; i++ ){
        for( j = 0 ; j < 3 ; j++ ){
            // fin ignores whitespace and newlines
            // We also keep our position in the file with fin
            fin >> data[i][j];
        }
    }
    
}

// Print out whatever matrix we wanted.
void Matrix::printMat(){
    
    int i, j;
    //cout << "Matrix:" << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl; // Newline for next row
    }
    cout << "\n";
    
}


int main() {

    // Z is zero matrix.
    Matrix Z;
    cout << "Matrix Z:" << endl;
    Z.printMat();
    
    // D is 2 diagonal, E is 1 diagonal.
    Matrix D(2);
    cout << "Matrix D:" << endl;
    D.printMat();
    Matrix E(1);
    cout << "Matrix E:" << endl;
    E.printMat();
    
    // A and C are the input file matrices. Initialize to zero first, then input stuff.
    Matrix A;
    Matrix C;
    A.inputMat();
    cout << "Matrix A:" << endl;
    A.printMat();
    C.inputMat();
    cout << "Matrix C:" << endl;
    C.printMat();
    fin.close(); // We are now done with our input file, so close it.
    
    // B is a copy of A.
    Matrix B(A);
    cout << "Matrix B:" << endl;
    B.printMat();
    
    
    return 0;
}

