## Searching in a Rotated Sorted Unique Elements Array

Searching in a rotated sorted array involves finding an element's index when the array has been rotated at an unknown pivot point. This approach can be used to search for an element in a rotated array with unique elements efficiently.

### Concept and Approach:

1. **Identify Pivot Point**:
   - Find the index of the smallest element (pivot) in the rotated array.
   - The pivot index indicates the point where the array was rotated.

2. **Binary Search on Segments**:
   - Perform binary search on two segments of the rotated array:
     1. The segment from the start of the array to the pivot (let's call it Segment A).
     2. The segment from the pivot to the end of the array (let's call it Segment B).

3. **Binary Search Algorithm**:
   - Choose the segment (A or B) where the target element might be present.
   - Perform a standard binary search in the chosen segment to find the target element's index.

4. **Advantages**:
   - This approach allows us to perform binary search in O(log n) time complexity even on a rotated array.
   - The idea of segmenting the array into two parts for binary search is the key to efficiently find the element.

### Example in C++:

Here's a C++ example illustrating searching in a rotated sorted array:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int searchInRotatedArray(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[left] <= arr[mid]) {
            // Left half is sorted
            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right half is sorted
            if (arr[mid] < target && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;  // Element not found
}

int main() {
    vector<int> rotatedArr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 3;

    int index = searchInRotatedArray(rotatedArr, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}
```

In this example, the rotated array `{7, 8, 9, 1, 2, 3, 4, 5, 6}` is searched for the target element `3`. The output will be:

```
Element 3 found at index 5
```

### Time Complexity:
- Binary search in rotated array: O(log n)

### Space Complexity:
- Constant space: O(1)