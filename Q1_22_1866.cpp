#include <iostream>
#include <string>
using namespace std;

// Function prototype for changelocation
void changelocation(char *string, int b1, int b2);

int main() {
  char* str;
  int len;

  // Prompt the user to enter the length of the string
  cout << "Enter the length of the string: ";
  cin >> len;

  // Dynamically allocate memory for the string
  str = new char[len + 1];

  // Prompt the user to enter the string
  cout << "Enter the string: ";
  cin >> str;

  int num1, num2;

  // Prompt the user to enter the boundaries to be replaced
  cout << "Enter the boundaries to be replaced: ";
  cin >> num1 >> num2;

  // Call the changelocation function to modify the string
  changelocation(str, num1, num2);

  // Display the modified string
  cout << "Modified string: " << str << endl;

  // Deallocate the memory for the string
  delete[] str;

  return 0;
}

// Function to change the location of characters at boundaries
void changelocation(char *string, int b1, int b2) {
  if (b1 < b2) {
    int r1 = b1 - 1;
    int r2 = b2 - 1;

    char st1 = string[r1];
    char st2 = string[r2];

    // Swap the characters at the specified boundaries
    string[r1] = st2;
    string[r2] = st1;

    // You can uncomment the following line if you want to perform
    // the swap recursively on the inner boundaries
    // changelocation(string, b1 + 1, b2 - 1);
  }
}

