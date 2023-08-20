## Subarray Sum Equals K

Subarray Sum Equals K is a problem that asks to find the total number of subarrays within an array whose sum equals a given value k. A subarray is a contiguous non-empty sequence of elements within the array.

### Concept and Approach:

1. **Prefix Sum in Arrays**:
   - Prefix sum is a technique that involves precomputing cumulative sums for each index in an array. It is used to efficiently calculate the sum of elements in a subarray (range) of the array.

2. **Precomputation**:
   - Create an array called `prefixSum` to store cumulative sums.
   - Iterate through the input array and calculate cumulative sums up to each index. Store these sums in the `prefixSum` array.

3. **Subarray Sum Calculation**:
   - To find subarrays with a sum of k:
     - For each index `i` from 0 to n-1, where `n` is the size of the array:
       - Calculate the target sum `target` as `prefixSum[i] - k`.
       - Check how many times the value `target` has appeared in the `prefixSum` array up to index `i`. This indicates how many subarrays ending at index `i` have a sum of `k`.

4. **Advantages**:
   - This approach efficiently handles the problem by converting it into a prefix sum problem, allowing us to calculate the sum of subarrays in constant time.
   - It is especially useful when dealing with multiple subarray sum queries on the same array.

### Example in C++:

Here's a C++ example solving the Subarray Sum Equals K problem using the prefix sum approach:

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int prefixSum = 0;
    unordered_map<int, int> prefixSumCount;

    // Initialize prefix sum count with 0 sum at index -1.
    prefixSumCount[0] = 1;

    for (int num : nums) {
        prefixSum += num;
        if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - k];
        }
        prefixSumCount[prefixSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = subarraySum(nums, k);
    cout << "Total subarrays with sum " << k << ": " << result << endl;

    return 0;
}
```

In this example, the `subarraySum` function uses the prefix sum approach to find the total number of subarrays with a sum of k. For the input `[1, 1, 1]` and k = 2, the output will be:

```
Total subarrays with sum 2: 2
```

### Time Complexity:
- The algorithm runs in O(n) time, where n is the size of the input array.

### Space Complexity:
- The algorithm uses an unordered map to store prefix sums and their counts, resulting in O(n) space complexity.