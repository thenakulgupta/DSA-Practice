/*
    Probleam: Coin Change (Tabulation).

    Input #1:
    3 4
    1 2 3

    Output #1:
    4


    Input #2:
    4 10
    2 5 3 6

    Output #2:
    5

*/

#include <iostream>
using namespace std;

int main() {
    int n, ts;
    cin >> n >> ts;
    int* coins = new int[n];
    int* ks = new int[n];
    int dp[n + 1][ts + 1];
    for (int i = 0;i < n;i++) {
        cin >> coins[i];
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
            int v = coins[i - 1];
            if (v <= j) {
                int ans1 = dp[i][j - v];
                int ans2 = dp[i - 1][j];
                dp[i][j] = ans1 + ans2;
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][ts];
    return 0;
}