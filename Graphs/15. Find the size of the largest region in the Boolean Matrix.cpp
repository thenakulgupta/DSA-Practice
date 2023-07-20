/*
    Probleam: Find the size of the largest region in the Boolean Matrix.

    Test Cases:
    Input #1
    4 5
    0 0 1 1 0
    0 0 1 1 0
    0 0 0 0 0
    0 0 0 0 1

    Output #1
    4


    Input #2
    4 5
    0 0 1 1 0
    1 0 1 1 0
    0 1 0 0 0
    0 0 0 0 1

    Output #2
    6
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> visited;

bool isSafe(int i, int j, int r, int c, vector<vector<bool>> arr, vector<vector<bool>> visited) {
    return i >= 0 && i < r && j >= 0 && j < c && arr[i][j] && !visited[i][j];
}

void getSizeUtil(vector<vector<bool>> v, int r, int c, int& count) {
    int rowNbr[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    int colNbr[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };

    visited[r][c] = true;

    for (int k = 0; k < 8; k++) {
        if (isSafe(r + rowNbr[k], c + colNbr[k], v.size(), v[0].size(), v, visited)) {
            count++;
            getSizeUtil(v, r + rowNbr[k], c + colNbr[k], count);
        }
    }
}

int getSize(vector<vector<bool>> v) {
    int result = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] && !visited[i][j]) {
                int count = 1;
                getSizeUtil(v, i, j, count);
                cout << endl << endl;
                result = max(result, count);
            }
        }
    }
    return result;
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<bool>> v;
    for (int i = 0;i < r;i++) {
        vector<bool> v1;
        vector<bool> visited1;
        for (int j = 0;j < c;j++) {
            int a;
            cin >> a;
            v1.push_back(a);
            visited1.push_back(false);
        }
        v.push_back(v1);
        visited.push_back(visited1);
    }
    cout << getSize(v);
    return 0;
}