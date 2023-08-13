## Trapping Water in Array

Trapping water in an array refers to the problem of calculating the amount of water that can be trapped between the bars of a given array, assuming that the array values represent the heights of bars. This problem simulates rainwater trapping between buildings, where the bars act as the building heights.

### Concept and Approach:

1. **Find Maximum Heights on Left and Right**:
   - For each position `i` in the array, find the maximum height bar on its left side and the maximum height bar on its right side.
   - This can be done through two separate passes over the array to precompute arrays storing maximum left and right heights.

2. **Calculate Trapped Water at Each Position**:
   - The trapped water at a position `i` is the minimum of the maximum height bars on its left and right minus the height of the bar at position `i`.
   - If the trapped water is negative or zero, there is no water trapped at that position.

3. **Sum Up Trapped Water**:
   - Sum up the trapped water at each position to get the total amount of trapped water in the array.

### Example in C++:

Here's a C++ example illustrating trapping water in an array:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int trapWater(const vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;  // Cannot trap water with less than 3 bars

    vector<int> maxLeft(n), maxRight(n);

    maxLeft[0] = height[0];
    for (int i = 1; i < n; ++i) {
        maxLeft[i] = max(maxLeft[i - 1], height[i]);
    }

    maxRight[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxRight[i] = max(maxRight[i + 1], height[i]);
    }

    int trappedWater = 0;
    for (int i = 1; i < n - 1; ++i) {
        int minHeight = min(maxLeft[i], maxRight[i]);
        trappedWater += max(0, minHeight - height[i]);
    }

    return trappedWater;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trappedWater = trapWater(height);

    cout << "Total trapped water: " << trappedWater << " units" << endl;

    return 0;
}
```

In this example, the array `height` represents the heights of bars. The `trapWater` function calculates the total amount of trapped water using the approach described above. The output will be:

```
Total trapped water: 6 units
```

### Time Complexity:
- Precomputing maximum left and right heights: O(n)
- Calculating trapped water: O(n)
- Overall time complexity: O(n)

### Space Complexity:
- Additional space for storing maximum left and right heights: O(n)