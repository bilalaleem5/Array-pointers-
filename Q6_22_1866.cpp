#include <iostream>
using namespace std;

// Function to calculate the sum of elements in a 2D array recursively
void calculateSumRecursive(int** arr, int i, int j, int rows, int cols, int& evenSum, int& oddSum) {
    // Base case 1: If we have reached the end of rows, return
    if (i == rows) {
        return;
    }
    // Base case 2: If we have reached the end of a row, move to the next row
    if (j == cols) {
        calculateSumRecursive(arr, i + 1, 0, rows, cols, evenSum, oddSum);
        return;
    }
    // Check if the current element is even or odd and update sums accordingly
    if (arr[i][j] % 2 == 0) {
        evenSum += arr[i][j];
    } else {
        oddSum += arr[i][j];
    }
    // Recursively call calculateSumRecursive for the next element
    calculateSumRecursive(arr, i, j + 1, rows, cols, evenSum, oddSum);
}

// Function to calculate the sum of elements in a 2D array
void calculateSum(int** arr, int rows, int cols) {
    int evenSum = 0, oddSum = 0;
    // Call the recursive function to calculate the sums
    calculateSumRecursive(arr, 0, 0, rows, cols, evenSum, oddSum);
    cout << "Sum of elements at even memory addresses: " << evenSum << endl;
    cout << "Sum of elements at odd memory addresses: " << oddSum << endl;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cout << "Enter element at index (" << i << ", " << j << "): ";
            cin >> arr[i][j];
        }
    }

    // Call the calculateSum function to compute the sums
    calculateSum(arr, rows, cols);

    // Deallocate memory for arrays
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

