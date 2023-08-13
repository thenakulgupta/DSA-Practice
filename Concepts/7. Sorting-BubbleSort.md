## Bubble Sort

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list of elements to be sorted, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated for each element in the list until the entire list is sorted. It's called "bubble sort" because smaller elements "bubble" to the top of the list while larger elements "sink" to the bottom.

### Concept and Approach:

1. **Start**: Begin at the beginning of the list.

2. **Passes**:
   - Repeat the following steps for each pass (iteration):
     - Traverse through the list from the beginning to the end.
     - Compare each pair of adjacent elements.
     - If the elements are out of order (larger element before the smaller one), swap them.

3. **Inner Loop**: The inner loop compares and swaps adjacent elements, gradually moving the largest unsorted element to its correct position at the end.

4. **Outer Loop**: The outer loop controls the number of passes required to sort the entire list.

5. **Optimization**: After each pass, the largest element in the unsorted portion of the list will be in its correct place. Thus, you can reduce the number of comparisons in the next pass by excluding the last element.

6. **Termination**: The sorting process is complete when no swaps are performed in a pass, indicating that all elements are in order.

### Example in C++:

Here's a C++ example illustrating the Bubble Sort algorithm:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

In this example, the Bubble Sort algorithm is used to sort the array `{64, 34, 25, 12, 22, 11, 90}`. After sorting, the output will be:

```
Original array: 64 34 25 12 22 11 90
Sorted array: 11 12 22 25 34 64 90
```

### Time Complexity:
- Best-case: O(n) (when the list is already sorted)
- Worst-case and Average-case: O(n^2)

### Space Complexity:
- O(1) (in-place sorting algorithm)