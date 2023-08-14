## Pairs of Songs With Total Durations Divisible by 60

Given a list of songs' durations, the task is to find the number of pairs of songs whose total duration is divisible by 60 seconds.

### Concept and Approach:

1. **Initialization**: Create an array called `remainders` of size 60 to keep track of the count of songs with each remainder when divided by 60. Also, initialize a variable `count` to keep track of the number of valid pairs.

2. **Iterating Through the List**:
   - Iterate through the list of song durations.
   - For each song's duration `t`, calculate its remainder when divided by 60, i.e., `t % 60`.
   - Update the `count` by adding the count of songs that, when combined with the current song, have a remainder of `60 - (t % 60)`.

3. **Updating Remainders Array**:
   - Increment the count of songs with remainder `t % 60` in the `remainders` array.

4. **Advantages**:
   - The approach leverages the fact that if `(time[i] + time[j]) % 60 == 0`, then `(time[i] % 60) + (time[j] % 60) == 60`.

### Example in C++:

Here's a C++ example illustrating the given solution:

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainders(60);
        int count = 0;
        for(int t : time) {
            if(t % 60 == 0) count += remainders[0];
            else count += remainders[60 - t % 60];
            remainders[t % 60]++;
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> time1 = {30, 20, 150, 100, 40};
    vector<int> time2 = {60, 60, 60};
    
    cout << "Output 1: " << solution.numPairsDivisibleBy60(time1) << endl;
    cout << "Output 2: " << solution.numPairsDivisibleBy60(time2) << endl;

    return 0;
}
```

In this example, the `numPairsDivisibleBy60` function from the provided solution is used to find the number of pairs for both cases. The output will be:

```
Output 1: 3
Output 2: 3
```

### Time Complexity:
- The approach iterates through the list of song durations once: O(n), where n is the length of the input array.

### Space Complexity:
- Additional space for storing remainders: O(60) = O(1)