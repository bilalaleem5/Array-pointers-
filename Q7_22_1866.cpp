#include <iostream>
#include <cstring>
using namespace std;

// Recursive function to count unique words in a string
void countUniqueWordsRecursive(char* str, char**& uwords, int*& size, int& count) {
    // Tokenize the input string to extract words
    char* word = strtok(str, " \n\t");
    if (word == NULL) {
        return; // Base case: If there are no more words, return
    }

    // Check if the word is already in the unique words list
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(uwords[i], word) == 0) {
            found = true;
            break;
        }
    }

    // If the word is not found in the unique words list, add it
    if (!found) {
        strcpy(uwords[count], word);
        size[count] = strlen(word);
        count++;
    }

    // Recursively call the function to process the next word
    countUniqueWordsRecursive(NULL, uwords, size, count);
}

// Function to count unique words in a string
void countUniqueWords(char* str, char**& uwords, int*& size) {
    const int MAX_WORDS = 1000;
    const int MAX_WORD_LENGTH = 100;
    uwords = new char*[MAX_WORDS];
    size = new int[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        uwords[i] = new char[MAX_WORD_LENGTH];
        size[i] = 0;
    }

    int count = 0;
    // Call the recursive function to count unique words
    countUniqueWordsRecursive(str, uwords, size, count);
}

int main() {
    const int MAX_TEXT_LENGTH = 1000;
    char text[MAX_TEXT_LENGTH];
    
    cout << "Enter your text: ";
    cin.getline(text, MAX_TEXT_LENGTH);

    char** uniqueWords;
    int* sizes;

    // Call the countUniqueWords function to count unique words in the text
    countUniqueWords(text, uniqueWords, sizes);

    // Display the unique words and their sizes
    for (int i = 0; sizes[i] != 0; i++) {
        cout << "Word: " << uniqueWords[i] << ", Size: " << sizes[i] << endl;
    }

    return 0;
}

