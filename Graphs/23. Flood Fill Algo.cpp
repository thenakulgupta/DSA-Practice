/*
    Probleam: Flood Fill Algo.

    Input:
    3 3 1 1 2
    1 1 1
    1 1 0
    1 0 1

    Output:
    2 2 2
    2 2 0
    2 0 1
*/

#include <iostream>
#include <vector>
using namespace std;

#define VII vector<vector<int>>
VII v;

bool isSafe(int sr, int sc) {
    return sr >= 0 && sr < v.size() && sc >= 0 && sc < v[0].size() && v[sr][sc] == 1;
}

void floodFillAlgo(int sr, int sc, int color) {
    int rowMoves[4] = { -1,1,0,0 };
    int colMoves[4] = { 0,0,-1,1 };
    for (int i = 0;i < 4;i++) {
        if (isSafe(sr + rowMoves[i], sc + colMoves[i])) {
            v[sr + rowMoves[i]][sc + colMoves[i]] = 2;
            floodFillAlgo(sr + rowMoves[i], sc + colMoves[i], color);
        }
    }
}

int main() {
    int m, n, sr, sc, color;
    cin >> m >> n >> sr >> sc >> color;
    for (int i = 0;i < m;i++) {
        vector<int> v1;
        for (int j = 0;j < n;j++) {
            int a;
            cin >> a;
            v1.push_back(a);
        }
        v.push_back(v1);
    }
    floodFillAlgo(sr, sc, color);
    for (int i = 0;i < v.size();i++) {
        for (int j = 0;j < v[0].size();j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}