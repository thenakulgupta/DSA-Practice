/*
    Probleam: Unbounded Knapsack (Tabulation).

    Input:
    5 7
    15 14 10 45 30
    2 5 1 3 4

    Output:
    100
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tw;
    cin >> n >> tw;
    int* val = new int[n];
    int* wt = new int[n];
    vector<vector<int>> dp;
    for (int i = 0;i < n;i++) {
        cin >> val[i];
    }
    for (int i = 0;i < n;i++) {
        cin >> wt[i];
    }
    for (int i = 0;i <= n;i++) {
        vector<int> v;
        for (int j = 0;j <= tw;j++) {
            v.push_back(0);
        }
        dp.push_back(v);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= tw;j++) {
            if (wt[i - 1] <= j) {
                // dp[i] instead of dp[i - 1] for unbounded knapsack instead of 0-1 knapsack.
                int ans1 = val[i - 1] + dp[i][j - wt[i - 1]];
                int ans2 = dp[i - 1][j];
                dp[i][j] = max(ans1, ans2);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][tw];
    return 0;
}