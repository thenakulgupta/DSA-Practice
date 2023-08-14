## Selection Sort

Selection Sort is a simple comparison-based sorting algorithm. It works by repeatedly selecting the smallest (or largest) element from the unsorted part of the array and putting it in the correct position in the sorted part of the array.

### Concept and Approach:

1. **Initial Array**: Given an unsorted array of elements.

2. **Selection Process**:
   - Find the minimum (or maximum) element in the unsorted portion of the array.
   - Swap this minimum (or maximum) element with the first element in the unsorted portion.

3. **Iterative Process**:
   - Continue the above selection process, but now consider the unsorted portion to be one element shorter (since the smallest (or largest) element is now in its correct position).
   - Repeat this process until the entire array becomes sorted.

4. **Example**:
   - Given array: `[64, 25, 12, 22, 11]`
   - Iterations:
     - Select the minimum element `11` and swap it with the first element `64`. Array becomes `[11, 25, 12, 22, 64]`.
     - Select the minimum element `12` from the remaining unsorted part and swap it with the second element `25`. Array becomes `[11, 12, 25, 22, 64]`.
     - Continue this process until the array is completely sorted.

5. **Advantages**:
   - Simple to understand and implement.
   - Suitable for small arrays or partially sorted arrays.

6. **Disadvantages**:
   - Inefficient for large arrays, as it has a time complexity of O(n^2), where n is the number of elements in the array.
   - Number of swaps is relatively high, which can be an issue in certain applications.

### Example in C++:

Here's a C++ example illustrating selection sort:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the current element at index 'i'
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

In this example, the selection sort algorithm is applied to the input array `{64, 25, 12, 22, 11}`, and the sorted array is printed as the output.

### Time Complexity:
- Best Case: O(n^2)
- Average Case: O(n^2)
- Worst Case: O(n^2)

### Space Complexity:
- O(1) (in-place sorting, no additional memory required)