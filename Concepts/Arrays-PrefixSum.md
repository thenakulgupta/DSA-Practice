## Prefix Sum in Arrays

Prefix sum is a technique used in array manipulation to efficiently calculate the sum of elements in a subarray (range) of an array. It precomputes cumulative sums for each index and uses these precomputed values to quickly find the sum of elements within a given range.

### Concept and Approach:

1. **Initialization**: Create a new array called `prefixSum` of the same size as the input array to store the cumulative sums.

2. **Precomputation**:
   - Start with `prefixSum[0]` equal to the first element of the input array.
   - Iterate through the input array from index 1 to the end.
   - For each index `i`, set `prefixSum[i] = prefixSum[i - 1] + arr[i]`, where `arr[i]` is the element at index `i` of the input array.

3. **Calculating Range Sum**:
   - To find the sum of elements in a specific range `[start, end]`, use the precomputed prefix sums:
   - If `start` is 0, then `rangeSum = prefixSum[end]`.
   - Otherwise, `rangeSum = prefixSum[end] - prefixSum[start - 1]`.

4. **Advantages**:
   - Calculating the prefix sum takes O(n) time complexity, but subsequent range sum queries take constant time O(1) since they involve simple subtractions of precomputed sums.
   - This technique is especially useful when you have multiple range sum queries on the same array.

### Example in C++:

Here's a C++ example illustrating prefix sum:

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> calculatePrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n);

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}

int main() {
    vector<int> arr = {3, 2, 8, 4, 9, 1, 5};
    vector<int> prefixSum = calculatePrefixSum(arr);

    int start = 2;
    int end = 5;
    int rangeSum = start == 0 ? prefixSum[end] : prefixSum[end] - prefixSum[start - 1];

    cout << "Sum of elements in range [" << start << ", " << end << "] is: " << rangeSum << endl;

    return 0;
}
```

In this example, the prefix sums of the input array `{3, 2, 8, 4, 9, 1, 5}` are precomputed, and then the sum of elements in the range `[2, 5]` is efficiently calculated using the prefix sums. The output will be:

```
Sum of elements in range [2, 5] is: 19
```

### Time Complexity:
- Calculating prefix sums: O(n)
- Range sum queries: O(1)

### Space Complexity:
- Additional space for storing prefix sums: O(n)