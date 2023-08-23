## Merge Sort

Merge Sort is a popular sorting algorithm that follows the divide-and-conquer paradigm to efficiently sort an array or a list of elements. It works by dividing the input array into smaller halves, sorting them individually, and then merging them back together in a sorted manner.

### Concept and Approach:

1. **Divide and Conquer**:
   - The algorithm starts by dividing the input array into two halves until each subarray contains only one element or becomes empty.
   - This process of dividing continues recursively until the base case is reached.

2. **Merge Operation**:
   - Once the base case is reached (subarrays of size 1 or empty), the merging process begins.
   - Merging involves taking two sorted subarrays and combining them to form a larger sorted subarray.
   - The merging process is done by comparing elements from the two subarrays and placing them in sorted order in a new auxiliary array.

3. **Merge Sort Algorithm**:
   - The merge sort algorithm is as follows:
     1. Divide the array into two halves.
     2. Recursively sort the left and right halves.
     3. Merge the sorted left and right halves.

### Example in C++:

Here's a C++ example illustrating the Merge Sort algorithm:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> sorted;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]){
            sorted.push_back(arr[i]);
            i++;
        }
        else{
            sorted.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid){
        sorted.push_back(arr[i]);
        i++
    }

    while (j <= end){
        sorted.push_back(arr[j]);
        j++
    }

    for (int i = start, k = 0; k < sorted.size(); ++i, ++k)
        arr[i] = sorted[k];
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main() {
    vector<int> arr = {6, 3, 9, 5, 2, 8};
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (const int& val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}
```

In this example, the input array `{6, 3, 9, 5, 2, 8}` is sorted using the Merge Sort algorithm. The output will be:

```
Sorted array: 2 3 5 6 8 9
```

### Time Complexity:
- Best, Average, and Worst Case: O(n log n)
  - The division step takes O(log n) time, and the merging step takes O(n) time.

### Space Complexity:
- Additional space for the merged array: O(n)
- The merging step requires extra space proportional to the size of the input array.

Merge Sort is efficient and stable (maintains the order of equal elements), making it a widely used sorting algorithm in various applications.