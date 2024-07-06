#include <iostream>
#include <string>

using namespace std;

int** deleteRow(int** matrix, int& rows, int cols, int rowToDelete) {
    int** newMatrix = new int* [rows - 1];

    for (int i = 0, k = 0; i < rows; ++i) {
        if (i == rowToDelete) {
            delete[] matrix[i]; 
            continue;
        }
        newMatrix[k] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            newMatrix[k][j] = matrix[i][j];
        }
        ++k;
    }

    return newMatrix;
}

int main() {
    int rows = 3;
    int cols = 3;

    int** matrix = new int* [rows];
    matrix[0] = new int[cols] {1, 2, 3};
    matrix[1] = new int[cols] {4, 5, 6};
    matrix[2] = new int[cols] {7, 8, 9};

    int rowToDelete = 1;

    matrix = deleteRow(matrix, rows, cols, rowToDelete);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

	system("pause");
	return 0;
}