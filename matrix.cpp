#include <iostream> // classic iostream
#include <iomanip> // used to print nicely
#include <fstream> // file ops
#include <vector> // used for the matrices
using namespace std;

// find and return the length of any int (used for printing matrices nicely)
int findLength(int num) {
    int len = 1;
    while (num /= 10) {
        len++;
    }
    return len;
}

// find and return the largest value in any matrix
int findMax(vector<vector<int>> &matrix) {
    int maxVal = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// take in a matrix and string, print the string as a title for the matrix, then print the matrix
void printMatrix(vector<vector<int>> &matrix, string name) {
    int max = findMax(matrix);
    int len = findLength(max);

    cout << "\n" << name << "\n";
    for (int i=0; i < matrix.size(); i++) {
        cout << "|";
        for (int j=0; j < matrix.size(); j++) {
        cout << setw(len+1) << matrix[i][j];
        }
        cout << "|" << endl;
    }
}

// performs [matrix1] + [matrix2] = [result]
void addMatrix(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, vector<vector<int>> &result) {
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1.size(); j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// performs [matrix1]-[matrix2]=[result]
void subtractMatrix(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, vector<vector<int>> &result) {
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1.size(); j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// performs [matrix1]*[matrix2]=[result]
void multiplyMatrix(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, vector<vector<int>> &result) {
    // zero out the result matrix first
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1.size(); j++) {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1.size(); j++) {
            for (int k = 0; k < matrix1.size(); k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// prompts user for a row and column to edit, along with a value, edits the matrix
void updateMatrix(vector<vector<int>> &matrix) {
    int row, col, val;
    cout << "\nEditing matrix... \n";
    cout << "Enter a row: ";
    cin >> row;
    cout << "Enter a column: ";
    cin >> col;
    cout << "Enter a value: ";
    cin >> val;
    if ((row >= matrix.size()) || (col >= matrix.size()) || (row <= 0) || (col <= 0)) {
        cout << "Row and/or col not valid. Matrix not updated.";
        return;
    }
    matrix[row-1][col-1] = val;
}
 
// prints the transpose of the passed in matrix
void transposeMatrix(vector<vector<int>> &matrix) {
    vector<vector<int>> transpose(matrix.size(), vector<int>(matrix.size()));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    printMatrix(transpose, "Transposed Matrix");
}

// main
int main() {
    int size;
    ifstream file("matrix_input.txt");
    file >> size;
    vector<vector<int>> matrix1(size, vector<int>(size));
    vector<vector<int>> matrix2(size, vector<int>(size));
    vector<vector<int>> result(size, vector<int>(size));
    // Reading in matrices
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrix1[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrix2[i][j];
        }
    }
    // print 'em
    printMatrix(matrix1, "Matrix 1");
    printMatrix(matrix2, "Matrix 2");

    // add 'em
    addMatrix(matrix1, matrix2, result);
    printMatrix(result, "Matrix Addition");

    // multiply
    multiplyMatrix(matrix1, matrix2, result);
    printMatrix(result, "Matrix Multiplication");
    
    // subtract
    subtractMatrix(matrix2, matrix1, result);
    printMatrix(result, "Matrix Subtraction");

    // prompt for new value, update it
    updateMatrix(matrix1);
    printMatrix(matrix1, "Updated Matrix");

    // find max
    cout << "Max value in Matrix1: " << findMax(matrix1);

    // transpose and print
    transposeMatrix(matrix1);
}