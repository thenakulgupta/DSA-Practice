/*
    Probleam: Target Sum Subset (Tabulation).

    Input:
    5 10
    4 2 7 1 3

    Output:
    1
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, ts;
    cin >> n >> ts;
    int* val = new int[n];
    int dp[n + 1][ts + 1];
    for (int i = 0;i < n;i++) {
        cin >> val[i];
    }
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= ts;j++) {
            if (j == 0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= ts;j++) {
            int v = val[i - 1];
            if (v <= ts && dp[i - 1][j - v] == 1) {
                dp[i][j] = dp[i - 1][j - v];
            }
            else if (dp[i - 1][j] == 1) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][ts];
    return 0;
}