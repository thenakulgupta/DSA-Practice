## Merge Sort - Majority Element

Finding the majority element in an array using the merge sort technique involves dividing the array into smaller subarrays, sorting them, and then combining them while keeping track of the majority element. This approach makes use of the fact that if an element is a majority element in the whole array, it must also be a majority element in at least one of the halves.

### Concept and Approach:

1. **Merge Sort with Majority Element Tracking**:
   - Implement the merge sort algorithm on the given array.
   - While merging two sorted subarrays, keep track of the majority element candidate.
   - If the majority element candidate appears more than ⌊n/2⌋ times in the combined subarrays, it is the overall majority element.

2. **Base Case**:
   - If the subarray contains only one element, return that element as the majority element candidate.

3. **Merging with Majority Element Check**:
   - When merging two sorted subarrays, count the occurrences of the majority element candidate in both subarrays.
   - If the count in any subarray is greater than ⌊n/2⌋, return the majority element candidate.

### Example in C++:

Here's a C++ example illustrating the majority element using merge sort:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int countInRange(const vector<int>& nums, int num, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; ++i) {
        if (nums[i] == num) {
            count++;
        }
    }
    return count;
}

int merge(vector<int>& nums, int left, int mid, int right) {
    int leftMajority = findMajority(nums, left, mid);
    int rightMajority = findMajority(nums, mid + 1, right);

    int leftCount = countInRange(nums, leftMajority, left, right);
    int rightCount = countInRange(nums, rightMajority, left, right);

    if (leftCount > (right - left + 1) / 2) {
        return leftMajority;
    } else if (rightCount > (right - left + 1) / 2) {
        return rightMajority;
    }

    return -1; // No majority element
}

int findMajority(const vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }

    int mid = left + (right - left) / 2;
    int leftMajority = findMajority(nums, left, mid);
    int rightMajority = findMajority(nums, mid + 1, right);

    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    return merge(nums, left, mid, right);
}

int majorityElement(vector<int>& nums) {
    return findMajority(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums1 = {3, 2, 3};
    cout << "Majority element: " << majorityElement(nums1) << endl;

    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority element: " << majorityElement(nums2) << endl;

    return 0;
}
```

The output will be:

```
Majority element: 3
Majority element: 2
```

### Time Complexity:
- The merge sort part has a time complexity of O(n log n).
- The majority element checking part has a linear time complexity O(n), where n is the size of the array.

The overall time complexity is O(n log n).

### Space Complexity:
- The space complexity depends on the recursive stack used during the merge sort. In this case, it's O(log n) due to the depth of the recursion.
- Additional space for variables and function calls: O(1)