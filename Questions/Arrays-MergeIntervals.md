## Merge Intervals

Merging intervals is a technique used to combine overlapping intervals in an array of intervals. Given an array of intervals, where each interval is represented as `[start, end]`, the goal is to merge overlapping intervals and return an array of non-overlapping intervals that cover all the intervals in the input.

### Concept and Approach:

1. **Sorting**: First, sort the intervals based on their start times. This step is crucial for efficiently merging overlapping intervals.

2. **Merging**:
   - Initialize an empty vector called `mergedIntervals` to store the merged intervals.
   - Iterate through the sorted intervals:
     - If the `mergedIntervals` vector is empty or if the current interval's start is greater than the end of the last interval in `mergedIntervals`, add the current interval to `mergedIntervals`.
     - Otherwise, there is an overlap between the current interval and the last interval in `mergedIntervals`. Merge these two intervals by updating the end time of the last interval in `mergedIntervals`.

### Example in C++:

Here's a C++ example illustrating the merging of intervals:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }

    sort(intervals.begin(), intervals.end());  // Sort intervals based on start times
    vector<vector<int>> mergedIntervals = {intervals[0]};

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] > mergedIntervals.back()[1]) {
            // No overlap, add new interval to mergedIntervals
            mergedIntervals.push_back(intervals[i]);
        } else {
            // Merge overlapping intervals
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
        }
    }

    return mergedIntervals;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = mergeIntervals(intervals);

    cout << "Merged Intervals: ";
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
```

In this example, the overlapping intervals `{1, 3}`, `{2, 6}` are merged into a single interval `{1, 6}`. The output will be:

```
Merged Intervals: [1, 6] [8, 10] [15, 18]
```

### Time Complexity:
- Sorting intervals: O(n log n), where n is the number of intervals.
- Merging overlapping intervals: O(n), as each interval is processed once.

### Space Complexity:
- Additional space for storing merged intervals: O(n)