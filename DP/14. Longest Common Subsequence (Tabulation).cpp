/*
    Probleam: Longest Common Subsequence (Tabulation).

    Input #1:
    abcde ace

    Output #1:
    3


    Input #2:
    abcdge abedg

    Output #2:
    4
*/

#include <iostream>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.length(), m = str2.length();
    int dp[n + 1][m + 1];
    for (int i = 0;i <= str1.length();i++) {
        for (int j = 0;j <= str2.length();j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                int ans1 = dp[i - 1][j];
                int ans2 = dp[i][j - 1];
                dp[i][j] = max(ans1, ans2);
            }
        }
    }

    cout << dp[n][m];
    return 0;
}