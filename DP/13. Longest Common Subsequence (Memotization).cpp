/*
    Probleam: Longest Common Subsequence (Memotization).

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
#include <vector>
using namespace std;

int lcs(string str1, string str2, int n, int m, vector<vector<int>> dp) {
    if (n <= 0 || m <= 0) {
        return 0;
    }
    if (dp[n - 1][m - 1] == -1) {
        if (str1[n - 1] == str2[m - 1]) {
            dp[n - 1][m - 1] = 1 + lcs(str1, str2, n - 1, m - 1, dp);
        }
        else {
            int ans1 = lcs(str1, str2, n - 1, m, dp);
            int ans2 = lcs(str1, str2, n, m - 1, dp);
            dp[n - 1][m - 1] = max(ans1, ans2);
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp;
    for (int i = 0;i < str1.length();i++) {
        vector<int> v;
        for (int j = 0;j < str2.length();j++) {
            v.push_back(-1);
        }
        dp.push_back(v);
    }

    cout << lcs(str1, str2, str1.length(), str2.length(), dp);
    return 0;
}