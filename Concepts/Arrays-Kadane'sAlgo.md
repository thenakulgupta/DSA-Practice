## Maximum Sum Subarray using Kadane's Algorithm

Kadane's algorithm is a popular approach to find the maximum sum subarray within an array. It efficiently handles both positive and negative numbers and has a time complexity of O(n).

### Concept and Approach:

1. **Initialization**:
   - Initialize two variables, `maxSum` and `currentSum`, both initially set to the first element of the array.

2. **Iterative Process**:
   - Iterate through the array starting from the second element.
   - For each element `num` at index `i`:
     - Update `currentSum` to the maximum of `num` and `currentSum + num`.
     - Update `maxSum` to the maximum of `maxSum` and `currentSum`.

3. **Advantages**:
   - The algorithm keeps track of the maximum sum subarray ending at each index, allowing it to handle negative numbers by restarting the subarray when a negative number is encountered.
   - It has a linear time complexity of O(n), making it efficient for large arrays.

### Example in C++:

Here's a C++ example illustrating Kadane's algorithm:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(const vector<int>& arr) {
    int n = arr.size();
    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < n; ++i) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = maxSubarraySum(arr);

    cout << "Maximum sum subarray: " << maxSum << endl;

    return 0;
}
```

In this example, the maximum sum subarray of the input array `{-2, 1, -3, 4, -1, 2, 1, -5, 4}` is found using Kadane's algorithm. The output will be:

```
Maximum sum subarray: 6
```

### Time Complexity:
- Iterating through the array: O(n)

### Space Complexity:
- Additional space for variables: O(1)