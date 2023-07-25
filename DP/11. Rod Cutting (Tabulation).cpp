/*
    Probleam: Rod Cutting (Tabulation).

    Input:
    8 8
    1 2 3 4 5 6 7 8
    1 5 8 9 10 17 17 20

    Output:
    22
*/

#include <iostream>
using namespace std;

int main() {
    int n, rl;
    cin >> n >> rl;
    int* length = new int[n];
    int* price = new int[n];
    int dp[n + 1][rl + 1];
    for (int i = 0;i < n;i++) {
        cin >> length[i];
    }
    for (int i = 0;i < n;i++) {
        cin >> price[i];
    }
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= rl;j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= rl;j++) {
            int l = length[i - 1];
            if (l <= j) {
                int ans1 = price[i - 1] + dp[i][j - l];
                int ans2 = dp[i - 1][j];
                dp[i][j] = max(ans1, ans2);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][rl];
    return 0;
}