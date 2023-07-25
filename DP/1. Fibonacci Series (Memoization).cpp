/*
    Probleam: Fibonacci Series (Memoization).

    Input:
    6

    Output:
    8
*/

#include <iostream>
using namespace std;

int fib(int n, int* dp) {
    if (n == 0 || n == 1) {
        return n;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int* dp = new int[n + 1];
    for (int i = 0;i <= n;i++) {
        dp[i] = 0;
    }
    cout << fib(n, dp);
    return 0;
}