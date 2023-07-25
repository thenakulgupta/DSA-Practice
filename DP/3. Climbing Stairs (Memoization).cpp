/*
    Probleam: Climbing Stairs (Memoization).

    Input:
    6

    Output:
    8
*/

#include <iostream>
using namespace std;

int countWays(int n, int* dp) {
    if (n == 0 || n == 1) {
        return n;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    // i - 1, i - 2, .... so on can be there. If 1,2 stairs allowed for then i - 1, i - 2.
    // if 1,2,3,4 stairs allowed then i-1,i-2,i-3,i-4.
    dp[n] = countWays(n - 1, dp) + countWays(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int* dp = new int[n + 1];
    for (int i = 0;i <= n;i++) {
        dp[i] = 0;
    }
    cout << countWays(n, dp);
    return 0;
}