## 3Sum Closest Problem

The 3Sum Closest problem is a variation of the classic 3Sum problem. Instead of finding three numbers in an array that sum up to a specific target value, you need to find three numbers whose sum is closest to a given target value. The problem can be solved using a two-pointer approach along with sorting the array.

### Concept and Approach:

1. **Sort the Array**:
   - Sort the given `nums` array in ascending order. Sorting helps in using the two-pointer approach effectively.

2. **Initialize Variables**:
   - Initialize `closestSum` with a large value like `INT_MAX` to keep track of the closest sum found.
   - Initialize `ans` to store the sum of the three integers that give the closest sum to the target.

3. **Three-Pointer Approach**:
   - Iterate through the array using a loop variable `k` from 0 to `n - 2`, where `n` is the size of the array.
   - For each `nums[k]`, use two pointers, `i` and `j`, initialized at `k + 1` and `n - 1` respectively.
   - Calculate the current sum `currSum` as `nums[k] + nums[i] + nums[j]`.

4. **Update Closest Sum**:
   - Compare the absolute difference between `currSum` and `target` with the current `closestSum`.
   - If the absolute difference is smaller, update `closestSum` with the new absolute difference and update `ans` with `currSum`.

5. **Adjust Pointers**:
   - If `currSum` is less than `target`, increment the `i` pointer to move towards larger values.
   - If `currSum` is greater than or equal to `target`, decrement the `j` pointer to move towards smaller values.

6. **Return Answer**:
   - After iterating through all combinations, return the `ans` value, which holds the sum of the three integers that give the closest sum to the target.

### Example in C++:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());

        for (int k = 0; k < n - 2; k++) {
            int num = nums[k];
            int i = k + 1;
            int j = n - 1;

            while (i < j) {
                int currSum = num + nums[i] + nums[j];
                if (abs(currSum - target) < closestSum) {
                    ans = currSum;
                    closestSum = abs(currSum - target);
                }
                if (currSum < target) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution solution;
    int result = solution.threeSumClosest(nums, target);
    cout << "Closest 3Sum to target " << target << " is: " << result << endl;
    return 0;
}
```

### Sample Output:

For the given `nums = [-1, 2, 1, -4]` and `target = 1`, the output will be:

```
Closest 3Sum to target 1 is: 2
```

### Time Complexity:
- Sorting the array: O(n log n)
- Main two-pointer loop: O(n^2)
- Overall: O(n^2)

### Space Complexity:
- Additional space used by variables: O(1)