/*
    Probleam: Minimum time required to rot all oranges.

    Test Cases:
    Input #1
    3 5
    2 1 0 2 1
    0 0 1 2 1
    1 0 0 2 1

    Output #1
    All oranges cannot be rotten


    Input #2
    3 5
    2 1 0 2 1
    0 0 1 2 1
    2 0 0 2 1

    Output #2
    2
*/

#include <iostream>
using namespace std;

bool isSafe(int i, int j, int r, int c) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

int main() {
    int r, c;
    cin >> r >> c;
    int arr[r][c];
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cin >> arr[i][j];
        }
    }
    int t = 0;
    bool changed = false;
    while (1) {
        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                if (arr[i][j] == 2) {
                    if (isSafe(i + 1, j, r, c) && arr[i + 1][j] == 1) {
                        arr[i + 1][j] = 2;
                        changed = true;
                    }
                    if (isSafe(i - 1, j, r, c) && arr[i - 1][j] == 1) {
                        arr[i - 1][j] = 2;
                        changed = true;
                    }
                    if (isSafe(i, j + 1, r, c) && arr[i][j + 1] == 1) {
                        arr[i][j + 1] = 2;
                        changed = true;
                    }
                    if (isSafe(i, j - 1, r, c) && arr[i][j - 1] == 1) {
                        arr[i][j - 1] = 2;
                        changed = true;
                    }
                }
            }
        }
        t += 1;
        if (!changed) {
            break;
        }
        changed = false;
    }
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            if (arr[i][j] == 1) {
                cout << "All oranges cannot be rotten";
                return 0;
            }
        }
    }
    cout << t;
    return 0;
}