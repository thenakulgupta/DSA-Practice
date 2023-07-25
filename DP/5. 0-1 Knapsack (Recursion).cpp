/*
    Probleam: 0-1 Knapsack (Recursion).

    Input:
    5 7
    15 14 10 45 30
    2 5 1 3 4

    Output:
    75
*/

#include <iostream>
using namespace std;

int getMaxProfit(int* val, int* wt, int n, int tw) {
    if (n == 0 || tw == 0) {
        return 0;
    }
    if (wt[n - 1] <= tw) {
        int ans1 = val[n - 1] + getMaxProfit(val, wt, n - 1, tw - wt[n - 1]);
        int ans2 = getMaxProfit(val, wt, n - 1, tw);
        return max(ans1, ans2);
    }
    else {
        return getMaxProfit(val, wt, n - 1, tw);
    }
}

int main() {
    int n, tw;
    cin >> n >> tw;
    int* val = new int[n];
    int* wt = new int[n];
    for (int i = 0;i < n;i++) {
        cin >> val[i];
    }
    for (int i = 0;i < n;i++) {
        cin >> wt[i];
    }
    cout << getMaxProfit(val, wt, n, tw);
    return 0;
}