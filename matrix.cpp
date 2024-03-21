#include <iostream> 
#include <fstream>
using namespace std;

int main() {
    int matrix1[][];
    int matrix2[][];
    int result[][];
    int size;
    readMatrix(matrix1, matrix2, size);
    

}

void readMatrix(int matrix1[][], int matrix2[][]) {
    fstream file("matrix_input.txt", ios::in);
    while(getline(file, line)) {
        std::cout << line << '\n';
    }
    file.close();
}