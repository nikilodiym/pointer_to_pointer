#include <iostream>
#include <string>

using namespace std;

int** addColumnAtPosition(int** matrix, int rows, int cols, const int* newColumn, int position) {
    int** newMatrix = new int* [rows];

    for (int i = 0; i < rows; ++i) {
        newMatrix[i] = new int[cols + 1];

        for (int j = 0; j < position; ++j) {
            newMatrix[i][j] = matrix[i][j];
        }

        newMatrix[i][position] = newColumn[i];

        for (int j = position; j < cols; ++j) {
            newMatrix[i][j + 1] = matrix[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
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

    int newColumn[] = { 10, 11, 12 };

    int position = 1;

    matrix = addColumnAtPosition(matrix, rows, cols, newColumn, position);
    cols++; 

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