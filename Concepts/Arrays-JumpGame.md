## Jump Game

The "Jump Game" problem involves determining whether it's possible to reach the last index of an integer array, where each element represents the maximum jump length that can be taken from that position.

### Concept and Approach:

1. **Initialization**: We start from the first index (position 0) and maintain a variable `target` that represents the farthest index we can currently reach.

2. **Iteration**:
   - We iterate through the array from index 0 to the `target` index.
   - For each index `i`, update the `target` to the maximum of the current `target` value and `i + nums[i]`. This represents the farthest index reachable from the current position.

3. **Check for Reaching the End**:
   - During the iteration, if the updated `target` value is greater than or equal to the last index of the array (`nums.size() - 1`), it means we can reach the end. In this case, return `true`.

4. **End of Loop**:
   - If the loop ends without finding a target that can reach the end index, return `false`.

### Example in C++:

Here's a C++ example solving the "Jump Game" problem:

```cpp
#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int target = 0;
    for (int i = 0; i <= target; ++i) {
        target = max(target, i + nums[i]);
        if (target >= nums.size() - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    bool result1 = canJump(nums1);
    bool result2 = canJump(nums2);

    cout << "Result 1: " << (result1 ? "true" : "false") << endl;
    cout << "Result 2: " << (result2 ? "true" : "false") << endl;

    return 0;
}
```

In this example, the `canJump` function checks if it's possible to reach the end of the array for both input cases. The outputs will be:

```
Result 1: true
Result 2: false
```

### Time Complexity:
- The loop iterates through the array once, making it O(n), where n is the length of the input array.

### Space Complexity:
- The space complexity is O(1), as no extra data structures are used apart from a few variables.