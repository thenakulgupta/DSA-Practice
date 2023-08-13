## Insertion Sort

Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is a comparison-based algorithm that works by repeatedly taking an element from the unsorted part of the array and inserting it into its correct position within the sorted part of the array.

### Concept and Approach:

1. **Initial Configuration**: Divide the array into two parts - a sorted part and an unsorted part. Initially, the sorted part contains the first element, and the rest of the array is the unsorted part.

2. **Iterative Process**:
   - Start iterating from the second element (index 1) of the array, which is considered the first element of the unsorted part.
   - Compare the current element with the elements in the sorted part, moving from right to left.
   - Shift elements in the sorted part that are greater than the current element to the right.
   - Insert the current element into the correct position within the sorted part.

3. **Repeat Until Sorted**:
   - Repeat the above steps for each subsequent element in the unsorted part of the array until the entire array is sorted.

4. **Advantages**:
   - Simple implementation.
   - Efficient for small datasets or nearly sorted arrays.
   - In-place sorting algorithm (requires constant extra space).

### Example in C++:

Here's a C++ example illustrating insertion sort:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 3};
    insertionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

In this example, the insertion sort algorithm is applied to the input array `{5, 2, 8, 1, 3}`. The sorted array `{1, 2, 3, 5, 8}` is printed as the output.

### Time Complexity:
- Best case: O(n) - When the array is already sorted.
- Worst case: O(n^2) - When the array is sorted in reverse order.
- Average case: O(n^2)

### Space Complexity:
- O(1) - In-place sorting, requires only a constant amount of extra space.