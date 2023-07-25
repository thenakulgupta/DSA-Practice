/*
    Probleam: Climbing Stairs (Tabulation).

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
            // i - 1, i - 2, .... so on can be there. If 1,2 stairs allowed for then i - 1, i - 2.
            // if 1,2,3,4 stairs allowed then i-1,i-2,i-3,i-4.
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    cout << dp[n];
    return 0;
}