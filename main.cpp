#include <iostream>
#include <string>

using namespace std;

int** addRow(int** matrix, int rows, int cols, const int* newRow) {
    int** newMatrix = new int* [rows + 1];

    for (int i = 0; i < rows; ++i) {
        newMatrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            newMatrix[i][j] = matrix[i][j];
        }
    }

    newMatrix[rows] = new int[cols];
    for (int j = 0; j < cols; ++j) {
        newMatrix[rows][j] = newRow[j];
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    return newMatrix;
}

int main() {
    int rows = 2;
    int cols = 3;

    int** matrix = new int* [rows];
    matrix[0] = new int[cols] {1, 2, 3};
    matrix[1] = new int[cols] {4, 5, 6};

    int newRow[] = { 7, 8, 9 };

    matrix = addRow(matrix, rows, cols, newRow);
    rows++; 

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;

	system("pause");
	return 0;
}