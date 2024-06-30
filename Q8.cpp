#include <iostream>

using namespace std;

bool CheckEqualSumArrays(int **p1, int **p2, int **p3, int R, int C) {
    if (R == 0 || C == 0) {
        return true;
    }

    int sum = **p1 + **p2;
    return (sum == **p3) && CheckEqualSumArrays(p1 + 1, p2 + 1, p3 + 1, R - 1, C);
}

bool CheckDifferentArrays(int **p1, int **p2, int **p3, int R, int C) {
    if (R == 0 || C == 0) {
        return true;
    }

    int diff = **p1 - **p2;
    return (diff == **p3) && CheckDifferentArrays(p1 + 1, p2 + 1, p3 + 1, R - 1, C);
}

bool CheckEqualArrays(int **p1, int **p2, int **p3, int R, int C) {
    if (R == 0 || C == 0) {
        return false;
    }

    return (**p1 == **p2 || **p1 == **p3 || **p2 == **p3) || CheckEqualArrays(p1 + 1, p2 + 1, p3 + 1, R - 1, C);
}

void FindSameRows(int **p1, int **p2, int **p3, int R, int C) {
    if (R == 0 || C == 0) {
        return;
    }

    bool sameRow = true;
    for (int i = 0; i < C; i++) {
        if (*(p1[i]) != *(p2[i]) || *(p1[i]) != *(p3[i])) {
            sameRow = false;
            break;
        }
    }

    if (sameRow) {
        cout << "Row " << R << " is the same in all three arrays." << endl;
    }

    FindSameRows(p1 + 1, p2 + 1, p3 + 1, R - 1, C);
}

void RotateArrays(int **p1, int **p2, int **p3, int R, int C) {
    if (R == 0 || C == 0) {
        return;
    }

    int temp = **p1;
    **p1 = **p2;
    **p2 = **p3;
    **p3 = temp;

    RotateArrays(p1 + 1, p2 + 1, p3 + 1, R - 1, C);
}

int main() {
    int R, C;

    cout << "Enter the number of rows and columns: ";
    cin >> R >> C;

    int **p1 = new int *[R];
    int **p2 = new int *[R];
    int **p3 = new int *[R];

    for (int i = 0; i < R; i++) {
        p1[i] = new int[C];
        p2[i] = new int[C];
        p3[i] = new int[C];
    }

    cout << "Enter values for p1:" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> p1[i][j];
        }
    }

    cout << "Enter values for p2:" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> p2[i][j];
        }
    }

    cout << "Enter values for p3:" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> p3[i][j];
        }
    }

    bool equalSum = CheckEqualSumArrays(p1, p2, p3, R, C);
    bool different = CheckDifferentArrays(p1, p2, p3, R, C);
    bool equalArrays = CheckEqualArrays(p1, p2, p3, R, C);
    FindSameRows(p1, p2, p3, R, C);
    RotateArrays(p1, p2, p3, R, C);

    cout << "1. Is the sum of any two arrays equal to the 3rd array? " << (equalSum ? "Yes" : "No") << endl;
    cout << "2. Is the difference of any two arrays equal to the 3rd array? " << (different ? "Yes" : "No") << endl;
    cout << "3. Are there any equal arrays among these? " << (equalArrays ? "Yes" : "No") << endl;

    for (int i = 0; i < R; i++) {
        delete[] p1[i];
        delete[] p2[i];
        delete[] p3[i];
    }
    delete[] p1;
    delete[] p2;
    delete[] p3;

    return 0;
}


