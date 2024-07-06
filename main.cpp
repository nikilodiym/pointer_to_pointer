#include <iostream>
#include <string>

using namespace std;

int** addRowAtPosition(int** matrix, int rows, int cols, const int* newRow, int position) {
    int** newMatrix = new int* [rows + 1];

    for (int i = 0; i < position; ++i) {
        newMatrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            newMatrix[i][j] = matrix[i][j];
        }
    }

    newMatrix[position] = new int[cols];
    for (int j = 0; j < cols; ++j) {
        newMatrix[position][j] = newRow[j];
    }

    for (int i = position; i < rows; ++i) {
        newMatrix[i + 1] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            newMatrix[i + 1][j] = matrix[i][j];
        }
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

    int position = 1;

    matrix = addRowAtPosition(matrix, rows, cols, newRow, position);
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