#include <iostream>
#include <string>

using namespace std;

int** deleteColumn(int** matrix, int rows, int& cols, int colToDelete) {
    int** newMatrix = new int* [rows];

    for (int i = 0; i < rows; ++i) {
        newMatrix[i] = new int[cols - 1];
        for (int j = 0, k = 0; j < cols; ++j) {
            if (j == colToDelete) {
                continue;
            }
            newMatrix[i][k] = matrix[i][j];
            ++k;
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

    int colToDelete = 1;

    matrix = deleteColumn(matrix, rows, cols, colToDelete);

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