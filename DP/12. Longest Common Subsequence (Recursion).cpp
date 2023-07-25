/*
    Probleam: Longest Common Subsequence (Recursion).

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

int lcs(string str1, string str2, int n, int m) {
    if (n <= 0 || m <= 0) {
        return 0;
    }
    if (str1[n - 1] == str2[m - 1]) {
        return 1 + lcs(str1, str2, n - 1, m - 1);
    }
    else {
        int ans1 = lcs(str1, str2, n - 1, m);
        int ans2 = lcs(str1, str2, n, m - 1);
        return max(ans1, ans2);
    }
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    cout << lcs(str1, str2, str1.length(), str2.length());
    return 0;
}