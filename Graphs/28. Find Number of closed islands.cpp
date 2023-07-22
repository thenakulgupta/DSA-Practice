/*
    Probleam: Find Number of closed islands.

    Input #1:
    3 3
    1 0 0
    0 1 0
    0 0 1

    Output #1:
    1


    Input #2:
    5 8
    0 0 0 0 0 0 0 1
    0 1 1 1 1 0 0 1
    0 1 0 1 0 0 0 1
    0 1 1 1 1 0 1 0
    0 0 0 0 0 0 0 1

    Output #2:
    11
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define VII vector<vector<int>>

VII v;
VII vis;

bool isSafe(int i, int j) {
    return i >= 1 && i < v.size() - 1 && j >= 1 && j < v[0].size() - 1 && v[i][j] == 1;
}

int findClosestIslands(int r = 1, int c = 1) {
    int rowMoves[4] = { -1,1,0,0 };
    int colMoves[4] = { 0,0,-1,1 };
    int ans = 0;
    for (int r = 0;r < v.size();r++) {
        for (int c = 0;c < v[r].size();c++) {
            queue<pair<int, int>> q;
            q.push({ r,c });
            if (isSafe(r, c)) {
                ans++;
                while (!q.empty()) {
                    auto p = q.front();
                    q.pop();
                    if (isSafe(p.first, p.second) && !vis[p.first][p.second]) {
                        vis[p.first][p.second] = true;
                        for (int i = 0;i < 4;i++) {
                            int newRow = p.first + rowMoves[i];
                            int newCol = p.second + colMoves[i];
                            if (isSafe(newRow, newCol) && !vis[newRow][newCol]) {
                                q.push({ newRow,newCol });
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        vector<int> v1;
        vector<int> v2;
        for (int j = 0;j < m;j++) {
            int a;
            cin >> a;
            v1.push_back(a);
            v2.push_back(false);
        }
        v.push_back(v1);
        vis.push_back(v2);
    }
    cout << findClosestIslands();
    return 0;
}