## Maximum Score from Cards

This problem involves selecting cards from the beginning or the end of an array to maximize the total score. A sliding window approach can be used to find the subarray with the minimum sum, which in turn helps in maximizing the remaining score.

### Concept and Approach:

1. **Total Score Calculation**: Calculate the sum of all the cards in the array and store it in `totalScore`.

2. **Case Handling**: If `k` is equal to the length of the `cardPoints` array, then all cards will be picked, so return `totalScore`.

3. **Sliding Window Strategy**:
   - Initialize `requiredSubarrayLength` as `cardPoints.size() - k`. This represents the number of cards to be left out.
   - Initialize `startingIndex` and `presentSubarrayScore` to 0. These keep track of the current subarray under consideration and its score.
   - Initialize `minSubarrayScore` with `totalScore`, as this variable will hold the minimum possible subarray sum.
   
4. **Iterate Over Array**:
   - Iterate through the array.
   - Add the current card's points to `presentSubarrayScore`.
   - Check if the size of the current subarray (`presentSubarrayLength`) is equal to `requiredSubarrayLength`.
   - If yes, compare `presentSubarrayScore` with `minSubarrayScore` and update `minSubarrayScore` if needed. Then, subtract the card's points at `startingIndex` and increment `startingIndex`.

5. **Calculate Maximum Score**:
   - Subtract `minSubarrayScore` from `totalScore` to obtain the maximum possible score.

### Example in C++:

Here's a C++ example implementing the sliding window approach:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int startingIndex = 0;
        int presentSubarrayScore = 0;
        int n = cardPoints.size();
        int requiredSubarrayLength = n - k;
        int minSubarrayScore;
        int totalScore = 0;

        // Calculate the total score by summing all the cards.
        for (int i : cardPoints) {
            totalScore += i;
        }
        
        minSubarrayScore = totalScore;

        // If all cards are selected, return total score.
        if (k == n) {
            return totalScore;
        }

        for (int i = 0; i < n; i++) {
            presentSubarrayScore += cardPoints[i];
            int presentSubarrayLength = i - startingIndex + 1;
            if (presentSubarrayLength == requiredSubarrayLength) {
                minSubarrayScore = min(minSubarrayScore, presentSubarrayScore);
                presentSubarrayScore -= cardPoints[startingIndex++];
            }
        }
        
        // Calculate and return the maximum obtainable score.
        return totalScore - minSubarrayScore;
    }
};

int main() {
    Solution solution;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    
    int maxScore = solution.maxScore(cardPoints, k);
    cout << "Maximum obtainable score: " << maxScore << endl;

    return 0;
}
```

In this example, the `maxScore` function calculates the maximum obtainable score using the sliding window approach. For the given input, the output will be:

```
Maximum obtainable score: 12
```

### Time Complexity:
- Iterating through the array: O(n)
- Overall time complexity: O(n)

### Space Complexity:
- Additional space used by variables: O(1)