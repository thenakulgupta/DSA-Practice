## Minimum Replacements to Sort the Array

In this problem, we are given an array of integers. We can replace any integer with two integers whose sum equals the replaced integer. The goal is to sort the array in non-decreasing order with a minimum number of such replacements.

### Concept and Approach:

1. **Understanding Constraints**: Our array is 0-indexed and its length is \(1 \leq nums.length \leq 10^5\). The array elements are between 1 and \(10^9\).

2. **Iterate Backwards**: Start iterating from the second last element of the array (`nums[nums.size() - 2]`) up to the first element (`nums[0]`).

3. **Check Condition**: For each element (`nums[i]`), compare it with the last element (`last`). The last element doesn't need to be replaced since it is the last number in the sorted array.

4. **Calculating Steps**: If `nums[i]` is greater than `last`, find out the minimum number of steps to break it down so that all its parts are less than or equal to `last`. Use the formula:

   ```
   Steps to split = (nums[i] - 1) / last
   ```
   
   **Why the `-1` in `nums[i] - 1`?**: This handles cases where `nums[i]` is divisible by `last`. Without the `-1`, we might end up with unnecessary splits that don't reduce the value of `nums[i]`.

5. **Updating 'last'**: After calculating the steps, we update the `last` variable. Calculate the smallest value that will be obtained after splitting `nums[i]`:

   ```
   New smallest element (last) = nums[i] / (steps + 1)
   ```
   
   Update `last` to this new smallest value, as it will serve as the reference for the next element.

6. **Update Answer**: Accumulate the steps needed for each element in a variable (`ans`).

### Code Example in C++:

```cpp
#include <iostream>
#include <vector>
using namespace std;

long long minimumReplacement(vector<int>& nums) {
    long long ans = 0;  // Initialize the answer variable
    int last = nums[nums.size() - 1];  // Initialize 'last' with the last element in the array

    // Start iterating from second last to the first element
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (last < nums[i]) {  // If current element is greater than 'last'
            int steps = (nums[i] - 1) / last;  // Calculate steps needed
            last = nums[i] / (steps + 1);  // Update 'last'
            ans += steps;  // Update the answer
        } else {
            last = nums[i];  // Update 'last'
        }
    }
    return ans;  // Return the final answer
}

int main() {
    vector<int> nums = {3, 9, 3};  // Sample input array
    long long ans = minimumReplacement(nums);  // Function call
    cout << "Minimum number of operations to sort the array: " << ans << endl;  // Print answer

    return 0;
}
```

### Output:

```
Minimum number of operations to sort the array: 2
```

### Time Complexity:

- Iterating through the array: O(n)

### Space Complexity:

- Additional space for storing steps and last: O(1)

By following this approach, we efficiently calculate the minimum number of operations required to sort the given array in non-decreasing order.
