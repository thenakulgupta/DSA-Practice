## Merge Sort - Inversion Count in Arrays

Inversion count in an array indicates how far or close the array is from being sorted. It measures the number of pairs of elements that are out of order in terms of their values. Formally, two elements `arr[i]` and `arr[j]` form an inversion if `arr[i] > arr[j]` and `i < j`.

### Concept and Approach:

1. **Initialization**: Initialize a variable `inversionCount` to keep track of the total number of inversions.

2. **Merge Sort Approach**:
   - We can use a modified version of the merge sort algorithm to count inversions efficiently.
   - The idea is to divide the array into smaller subarrays, recursively count inversions in them, and then merge these subarrays while counting additional inversions introduced during the merging process.

3. **Merge and Count**:
   - During the merge step, when merging two sorted subarrays, if an element `arr[i]` in the left subarray is greater than an element `arr[j]` in the right subarray, it forms `mid - i + 1` inversions because all elements to the right of `i` are also greater than `arr[j]`.
   - Increment `inversionCount` by `mid - i + 1`.

4. **Recursive Process**:
   - Divide the array into two halves: left and right.
   - Recursively count inversions in both halves.
   - Merge the two halves while also counting additional inversions.

5. **Base Case**:
   - If the array has only one element, it is already sorted, and the inversion count is 0.
   - Return the inversion count as 0.

### Example in C++:

Here's a C++ example illustrating the inversion count calculation using the merge sort approach:

```cpp
#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCountInversions(vector<int>& vec, int start, int mid, int end) {
    vector<int> sorted;
    int i = start, j = mid + 1;
    long long ans = 0;
    while (i <= mid && j <= end) {
        if (vec[i] > vec[j]) {
            sorted.push_back(vec[j]);
            j++;
            ans += mid - i + 1;
        }
        else {
            sorted.push_back(vec[i]);
            i++;
        }
    }
    while (i <= mid) {
        sorted.push_back(vec[i]);
        i++;
    }
    while (j <= end) {
        sorted.push_back(vec[j]);
        j++;
    }
    for (int i = start, k = 0;k < sorted.size();i++, k++) {
        vec[i] = sorted[k];
    }
    return ans;
}

long long mergeSortAndCountInversions(vector<int>& arr, int left, int right) {
    long long inversionCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;
        inversionCount += mergeSortAndCountInversions(arr, left, mid);
        inversionCount += mergeSortAndCountInversions(arr, mid + 1, right);
        inversionCount += mergeAndCountInversions(arr, left, mid, right);
    }

    return inversionCount;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();

    long long inversionCount = mergeSortAndCountInversions(arr, 0, n - 1);

    cout << "Inversion Count: " << inversionCount << endl;

    return 0;
}
```

In this example, the inversion count in the array `{2, 4, 1, 3, 5}` is calculated using the merge sort approach.

The output will be:

```
Inversion Count: 3
```

### Time Complexity:
- The merge sort algorithm used to count inversions has a time complexity of O(n log n).

### Space Complexity:
- Additional space for the temporary array during merging: O(n)
- Recursive call stack space: O(log n)