/*
    Probleam: Fibonacci Series (Tabulation).

    Input:
    6

    Output:
    8
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* dp = new int[n + 1];
    for (int i = 0;i <= n;i++) {
        if (i < 2) {
            dp[i] = i;
        }
        else {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    cout << dp[n];
    return 0;
}