## Quick Sort

Quick Sort is a popular and efficient sorting algorithm that employs a divide-and-conquer strategy to sort an array or a list of elements. It works by selecting a 'pivot' element and partitioning the array into two sub-arrays – one containing elements smaller than the pivot and the other containing elements greater than the pivot. It then recursively sorts these sub-arrays.

### Concept and Approach:

1. **Choose Pivot**: Select a pivot element from the array. It could be chosen randomly, or typically the first, last, or middle element is used as the pivot.

2. **Partitioning**:
   - Rearrange the array such that all elements less than the pivot are on the left side, and all elements greater than the pivot are on the right side.
   - This partitioning step places the pivot in its final sorted position.

3. **Recursion**:
   - Recursively apply the above two steps to the sub-arrays on the left and right of the pivot.
   - Continue until each sub-array contains only one element, making the entire array sorted.

4. **Combine**:
   - Since each sub-array is sorted, no additional work is needed to combine them.
   - The entire array is now sorted.

5. **Advantages**:
   - Quick Sort is highly efficient and widely used in practice.
   - It's an "in-place" sorting algorithm, meaning it doesn't require additional memory for auxiliary arrays.
   - It has an average-case time complexity of O(n log n), which makes it faster than many other sorting algorithms.

### Example in C++:

Here's a C++ example illustrating the Quick Sort algorithm:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {5, 9, 3, 6, 1, 8, 4, 7, 2};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

In this example, the array `{5, 9, 3, 6, 1, 8, 4, 7, 2}` is sorted using the Quick Sort algorithm.

The output will be:

```
Sorted array: 1 2 3 4 5 6 7 8 9
```

### Time Complexity:
- Best-case time complexity: O(n log n)
- Average-case time complexity: O(n log n)
- Worst-case time complexity: O(n^2) (but can be improved using various pivot selection strategies)
  
### Space Complexity:
- Quick Sort is an in-place sorting algorithm, meaning it doesn't require additional memory for auxiliary arrays.
- The space complexity of the algorithm is O(log n) due to the recursion stack.