#include <iostream>
using namespace std;

const int MAX_NUM = 100; // Assuming the maximum number in the input is 100

// Function to find occurrences of elements in an array
void findOccurrences(int *Elements, int S, int *occurrences, int i = 0) {
    // Base case: If we have processed all elements in the array, return
    if (i < S) {
        // Increment the count of the current element in the occurrences array
        occurrences[Elements[i]]++;
        // Recursively call findOccurrences for the next element in the array
        findOccurrences(Elements, S, occurrences, i + 1);
    }
}

// Function to display the occurrences of elements
void displayOccurrences(int *occurrences, int num = MAX_NUM - 1) {
    // Base case: If we have displayed all elements or reached the end of the occurrences array, return
    if (num >= 0) {
        // If the count of the current element is greater than 0, display it
        if (occurrences[num] > 0) {
            cout << num << "\t" << occurrences[num] << endl;
        }
        // Recursively call displayOccurrences for the next element in the occurrences array
        displayOccurrences(occurrences, num - 1);
    }
}

int main() {
    int S;
    cout << "Enter the number of elements in the array: ";
    cin >> S;
    int *Elements = new int[S];

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < S; i++) {
        cin >> Elements[i];
    }

    int *occurrences = new int[MAX_NUM] {0}; // Initialize occurrences array to all zeros
    findOccurrences(Elements, S, occurrences);

    cout << "Number\tOccurrences" << endl;
    displayOccurrences(occurrences);

    // Deallocate memory for arrays
    delete[] Elements;
    delete[] occurrences;
    
    return 0;
}

