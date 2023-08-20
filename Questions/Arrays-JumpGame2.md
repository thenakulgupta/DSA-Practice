## Jump Game II

Given an array `nums` representing the maximum length of a forward jump from each index, the task is to find the minimum number of jumps needed to reach the last index.

### Concept and Approach:

1. **Initialization**: Initialize variables to keep track of the current position (`currentPos`), the maximum reachable index (`maxReach`), the number of jumps (`jumps`), and the next potential position (`nextPos`).

2. **Iteration**:
   - Start iterating through the array from index 0 to the second-to-last index.
   - For each index `i`, update `maxReach` as the maximum of its current value and `i + nums[i]`. This determines the farthest index we can reach from the current position.
   - If `i` is equal to `currentPos`, update `nextPos` to `maxReach` and increment `jumps` by 1. This means we're about to jump to a new position.

3. **Jump**:
   - If the `currentPos` is equal to `nextPos`, we need to make a jump.
   - Update `currentPos` to `nextPos`.

4. **Termination**:
   - Continue these steps until `currentPos` reaches the last index.

5. **Result**:
   - The value of `jumps` will be the minimum number of jumps needed to reach the last index.

### Example in C++:

Here's a C++ example illustrating the approach:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int minJumps(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
        return 0;
    }

    int currentPos = 0;
    int maxReach = 0;
    int jumps = 0;
    int nextPos = 0;

    for (int i = 0; i < n - 1; ++i) {
        maxReach = max(maxReach, i + nums[i]);
        if (i == currentPos) {
            nextPos = maxReach;
            jumps++;
            currentPos = nextPos;
        }
    }

    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    int minJumpsRequired = minJumps(nums);

    cout << "Minimum jumps required: " << minJumpsRequired << endl;

    return 0;
}
```

In this example, the array `[2, 3, 1, 1, 4]` represents the maximum jump lengths. The code calculates the minimum number of jumps needed to reach the last index. The output will be:

```
Minimum jumps required: 2
```

### Time Complexity:
- The approach involves a single pass through the array, so the time complexity is O(n).

### Space Complexity:
- The approach uses a constant amount of additional space, so the space complexity is O(1).