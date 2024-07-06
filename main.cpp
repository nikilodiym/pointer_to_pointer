#include <iostream>
#include <string>

using namespace std;

void shiftRows(int** matrix, int M, int N, int shifts, bool rightDirection) {
    for (int s = 0; s < shifts; ++s) {
        for (int i = 0; i < M; ++i) {
            if (rightDirection) {
                int lastElement = matrix[i][N - 1];
                for (int j = N - 1; j > 0; --j) {
                    matrix[i][j] = matrix[i][j - 1];
                }
                matrix[i][0] = lastElement;
            }
            else {
                int firstElement = matrix[i][0];
                for (int j = 0; j < N - 1; ++j) {
                    matrix[i][j] = matrix[i][j + 1];
                }
                matrix[i][N - 1] = firstElement;
            }
        }
    }
}

void shiftColumns(int** matrix, int M, int N, int shifts, bool downDirection) {
    for (int s = 0; s < shifts; ++s) {
        for (int j = 0; j < N; ++j) {
            if (downDirection) {
                int lastElement = matrix[M - 1][j];
                for (int i = M - 1; i > 0; --i) {
                    matrix[i][j] = matrix[i - 1][j];
                }
                matrix[0][j] = lastElement;
            }
            else {
                int firstElement = matrix[0][j];
                for (int i = 0; i < M - 1; ++i) {
                    matrix[i][j] = matrix[i + 1][j];
                }
                matrix[M - 1][j] = firstElement;
            }
        }
    }
}

void printMatrix(int** matrix, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int M, N;
    cout << "Enter number of rows (M): ";
    cin >> M;
    cout << "Enter number of columns (N): ";
    cin >> N;

    int** matrix = new int* [M];
    int count = 1;
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = count++;
        }
    }

    cout << "Initial matrix:" << endl;
    printMatrix(matrix, M, N);

    shiftRows(matrix, M, N, 2, true);
    cout << "Matrix after shifting rows to the right 2 times:" << endl;
    printMatrix(matrix, M, N);

    shiftColumns(matrix, M, N, 1, true);
    cout << "Matrix after shifting columns down 1 time:" << endl;
    printMatrix(matrix, M, N);

    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;

	system("pause");
	return 0;
}