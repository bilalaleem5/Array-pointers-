#include <iostream>
using namespace std;

// Helper function to count inversions in a 2D array
int countInversionsHelper(int** arr, int i, int j, int n) {
    // Base case: If we have reached the end of the array, return 0
    if (i == n) {
        return 0;
    }
    // If we have reached the end of a row, move to the next row
    if (j == n) {
        return countInversionsHelper(arr, i + 1, i + 2, n);
    }
    // Initialize a count variable to count inversions
    int count = (arr[i][j] > arr[i][i]) ? 1 : 0;
    // Recursively count inversions in the rest of the array
    return count + countInversionsHelper(arr, i, j + 1, n);
}

// Function to count inversions in a 2D array
int countInversions(int** arr, int n) {
    return countInversionsHelper(arr, 0, 1, n);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cout << "Enter element at index (" << i << ", " << j << "): ";
            cin >> arr[i][j];
        }
    }

    // Call the countInversions function to count inversions in the array
    int inversions = countInversions(arr, n);
    cout << "Number of inversions: " << inversions << endl;

    // Deallocate memory for arrays
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

