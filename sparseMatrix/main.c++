#include <iostream>
using namespace std;
void inputMatrix(int **&arr, int &count, int &row, int &column) {
    cout << "Enter number of rows:";
    cin >> row;
    cout << "Enter number of columns:";
    cin >> column;

    // Creating 2D array dynamically
    arr = new int *[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[column];
    }
    // Input elements
    cout << "ENTER MATRIX" << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "Enter data for " << i << j << " position : ";
            cin >> arr[i][j];

            // counting non zero elements
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }
}

void sparseMatrix(int **&arr, int **&sparse, int &count, int &row, int &column) {
    // Creating 2D array dynamically
    sparse = new int *[count + 1];

    for (int i = 0; i < count + 1; i++) {
        sparse[i] = new int[3];
    }

    // Adding 1st row
    sparse[0][0] = row;
    sparse[0][1] = column;
    sparse[0][2] = count;

    // Adding rest of the rows
    int k = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (arr[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }

    cout << endl;
}
void printMatrix(int **&matrix, int row, int column) {
    cout << "PRINTING SPARSE MATRIX" << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int row;
    int column;
    int count = 0;
    // Input 2D array
    int **arr;
    inputMatrix(arr, count, row, column);

    // Creating sparse matrix
    int **sparse;
    sparseMatrix(arr, sparse, count, row, column);

    // Printing sparse matrix
    printMatrix(sparse, count + 1, 3);
}
