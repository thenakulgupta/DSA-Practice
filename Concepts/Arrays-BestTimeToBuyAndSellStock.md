## Maximizing Profits with Stock Transactions

This problem involves finding the maximum profit that can be achieved by buying and selling stocks on different days. You can perform multiple transactions on the same day (buy and sell immediately) and need to find the total profit achievable.

### Concept and Approach:

1. **Iterative Approach**: Loop through the given price array and make transactions whenever a profitable opportunity arises.

2. **Initializing Variables**:
   - Initialize a variable `maxProfit` to keep track of the total profit.
   - Start iterating from index 1 (day 2) since you need to compare with the previous day's price.

3. **Transaction Logic**:
   - If the price on the current day is greater than the price on the previous day, there is a potential profit opportunity.
   - Buy the stock on the previous day and sell it on the current day, gaining a profit of `prices[i] - prices[i-1]`.
   - Accumulate this profit in the `maxProfit` variable.

4. **Example**:
   - Given the prices `[7, 1, 5, 3, 6, 4]`, you would buy on day 2 (price = 1) and sell on day 3 (price = 5), gaining a profit of 4.
   - Then buy on day 4 (price = 3) and sell on day 5 (price = 6), gaining a profit of 3.
   - Total profit is 7 (4 + 3).

5. **Advantages**:
   - This approach takes advantage of the fact that you can perform multiple transactions on the same day if there's a potential profit.
   - You're not restricted to holding onto a stock for a single day.

### Example in C++:

Here's a C++ example implementing the approach:

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = solution.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}
```

In this example, the `maxProfit` function calculates the maximum achievable profit by iterating through the given prices array. The result for the input `[7, 1, 5, 3, 6, 4]` will be:

```
Maximum profit: 7
```

### Time Complexity:
- Since you're iterating through the array once, the time complexity is O(n), where n is the number of days.

### Space Complexity:
- The space complexity is O(1) since you're using a constant amount of extra space to store the `maxProfit` variable.