## Binary Search in Sorted Arrays

Binary search is an efficient searching algorithm used to find the position of a target value within a sorted array. It repeatedly divides the search range in half, narrowing down the possibilities by comparing the middle element of the current range to the target value.

### Concept and Approach:

1. **Initialization**: 
   - Binary search requires a sorted array as input.
   - Define variables `low` and `high` to represent the current search range. Initially, `low` is set to the first index (0) and `high` to the last index (n - 1) of the array.

2. **Search Iteration**:
   - Calculate the middle index as `mid = (low + high) / 2`.
   - Compare the element at index `mid` to the target value.
     - If the middle element is equal to the target, the search is successful, and `mid` is the index of the target.
     - If the middle element is less than the target, update `low = mid + 1` to search the right half.
     - If the middle element is greater than the target, update `high = mid - 1` to search the left half.

3. **Termination**:
   - Repeat the search iteration until `low` becomes greater than `high`. This indicates that the search range is empty, and the target is not present in the array.

4. **Advantages**:
   - Binary search has a time complexity of O(log n), which is much faster than linear search (O(n)) for large arrays.
   - It efficiently narrows down the search range, making it particularly useful for sorted arrays.

### Example in C++:

Here's a C++ example illustrating binary search in a sorted array:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  // Target found at index mid
        } else if (arr[mid] < target) {
            low = mid + 1;  // Search the right half
        } else {
            high = mid - 1;  // Search the left half
        }
    }

    return -1;  // Target not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;

    int index = binarySearch(arr, target);
    if (index != -1) {
        cout << "Target " << target << " found at index " << index << endl;
    } else {
        cout << "Target " << target << " not found in the array" << endl;
    }

    return 0;
}
```

In this example, binary search is used to find the index of the target value `7` in the sorted array `{1, 3, 5, 7, 9, 11, 13}`. The output will be:

```
Target 7 found at index 3
```

### Time Complexity:
- Binary search: O(log n)

### Space Complexity:
- Constant space is used, O(1)