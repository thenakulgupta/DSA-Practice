## Counting Sort

Counting Sort is a sorting algorithm that works well when the range of input values is small. It's efficient and performs well for integer-based arrays.

### Concept and Approach:

1. **Counting Array**: Create a counting array to store the count of each distinct element in the input array. The counting array's size should be determined by the maximum value in the input array.

2. **Counting Occurrences**: Traverse the input array and update the counting array by incrementing the count at the index corresponding to each element.

3. **Cumulative Counts**: Modify the counting array to store cumulative counts. Each element at index `i` should represent the total count of elements less than or equal to `i`.

4. **Sorted Output Array**: Create an output array of the same size as the input array. Traverse the input array again, use the counting array to determine the correct position of each element in the output array, and decrement the cumulative count in the counting array for each element placed in the output array.

### Example in C++:

Here's a C++ example illustrating counting sort:

```cpp
#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();
    
    // Find the maximum element to determine counting array size
    int maxVal = *max_element(arr.begin(), arr.end());

    // Create and initialize the counting array
    vector<int> countArray(maxVal + 1, 0);
    
    // Count occurrences of each element
    for (int num : arr) {
        countArray[num]++;
    }
    
    // Update the counting array to hold cumulative counts
    for (int i = 1; i <= maxVal; ++i) {
        countArray[i] += countArray[i - 1];
    }

    // Create the output array and populate it using the counting array
    vector<int> outputArray(n);
    for (int i = n - 1; i >= 0; --i) {
        outputArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }

    // Copy the sorted output back to the original array
    arr = outputArray;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

OR

```cpp
int main() {
    vector<int> nums = {4, 2, 2, 8, 3, 3, 1};
    int n=nums.size();
    map<int, int> map;

    for(int i=0;i<n;i++){
        if(map.count(nums[i])==0){
            map[nums[i]] = 0;
        }
        map[nums[i]]++;
    }

    nums.clear();

    for(auto &[n,j]:map){
        for(int i=0;i<j;i++){
            nums.push_back(n);
        }
    }

    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

In this example, the counting sort algorithm is applied to the input array `{4, 2, 2, 8, 3, 3, 1}`. The output will be:

```
Sorted array: 1 2 2 3 3 4 8
```

### Time Complexity:
- Counting occurrences: O(n)
- Calculating cumulative counts: O(k) where k is the range of input values
- Creating the sorted output array: O(n)
- Overall time complexity: O(n + k)

### Space Complexity:
- Additional space for the counting array: O(k)
- Additional space for the output array: O(n)
- Overall space complexity: O(n + k)