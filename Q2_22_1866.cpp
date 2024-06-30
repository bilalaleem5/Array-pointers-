#include <iostream>
using namespace std;

// Function to print the pattern
void pattern(int n, int r = 1, int c = 1) {
    // Base case: If we have printed all rows, return
    if (r > n)
        return;

    // If we are within the current row's boundary
    if (c <= n - r + 1) {
        // Recursively call pattern for the current row and column
        pattern(n, r, c + 1);

        // Print either 'r' or '1' based on the column number
        if (c == 1)
            cout << r << " "; // Print 'r' for the first column
        else
            cout << 1 << " "; // Print '1' for other columns
    } else {
        // If we are outside the current row's boundary, move to the next row
        pattern(n, r + 1);

        // Print a newline to start a new row
        cout << endl;
    }
}

int main() {
    int n;

    // Prompt the user to enter a number
    cout << "Enter number: ";
    cin >> n;

    // Call the pattern function with the input number
    pattern(n);

    return 0;
}

