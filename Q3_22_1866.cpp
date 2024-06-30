#include <iostream>
#include <string>
using namespace std;

// Function to check if one string is a subsequent of another
bool checkSubsequent(string str1, string str2, int m, int n) {
    // Base case: If we have matched all characters in str1, it's a subsequent
    if (m == 0)
        return true;

    // Base case: If we have exhausted str2 but not matched all of str1, it's not a subsequent
    if (n == 0)
        return false;

    // If the last characters of both strings match, continue checking the rest of the strings
    if (str1[m - 1] == str2[n - 1])
        return checkSubsequent(str1, str2, m - 1, n - 1);
    
    // If the last characters do not match, continue checking str2 without considering the last character
    return checkSubsequent(str1, str2, m, n - 1);
}

int main() {
    string str1, str2;

    // Prompt the user to enter two strings
    cout << "Enter string 1: ";
    cin >> str1;
    cout << "Enter string 2: ";
    cin >> str2;

    // Call the checkSubsequent function with the input strings
    bool result = checkSubsequent(str2, str1, str2.size(), str1.size());

    // Display the result
    if (result)
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}

