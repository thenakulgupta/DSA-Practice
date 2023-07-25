/*
    Probleam: 0-1 Knapsack (Memoization).

    Input:
    5 7
    15 14 10 45 30
    2 5 1 3 4

    Output:
    75
*/

#include <iostream>
#include <vector>
using namespace std;

int getMaxProfit(int* val, int* wt, int n, int tw, vector<vector<int>> dp) {
    if (n == 0 || tw == 0) {
        return 0;
    }
    if (dp[n - 1][tw] == -1) {
        if (wt[n - 1] <= tw) {
            int ans1 = val[n - 1] + getMaxProfit(val, wt, n - 1, tw - wt[n - 1], dp);
            int ans2 = getMaxProfit(val, wt, n - 1, tw, dp);
            dp[n - 1][tw] = max(ans1, ans2);
        }
        else {
            dp[n - 1][tw] = getMaxProfit(val, wt, n - 1, tw, dp);
        }
    }
    return dp[n - 1][tw];
}

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
            v.push_back(-1);
        }
        dp.push_back(v);
    }
    cout << getMaxProfit(val, wt, n, tw, dp);
    return 0;
}