## Minimum Window Substring

The Minimum Window Substring problem involves finding the smallest window (substring) within a given string `s` that contains all the characters of another string `t`.

### Concept and Approach:

1. **Initialization**: Initialize two unordered maps, `tCount` and `sCount`, to keep track of character frequencies in strings `t` and `s`.

2. **Counting Character Frequencies**:
   - Traverse through the characters of string `t` and populate the `tCount` map with the frequency of each character.

3. **Sliding Window Technique**:
   - Use the sliding window technique to maintain a window within string `s` that contains all the characters from `t`.
   - Initialize two pointers, `left` and `right`, both starting at the beginning of the string.
   - Initialize variables `required` to store the number of distinct characters in `t`, and `formed` to count how many distinct characters from `t` are currently formed in the window.
   - Also, initialize `windowLen` to a large value and `windowStart` to 0 to keep track of the minimum window found.

4. **Expanding the Window**:
   - Move the `right` pointer to expand the window to the right.
   - For each character `c` encountered, increment its frequency in the `sCount` map.
   - Check if `c` is present in the `tCount` map, and if the frequency of `c` in `sCount` becomes equal to that in `tCount`, increment the `formed` count.

5. **Contracting the Window**:
   - While the `formed` count is equal to the `required` count (meaning all characters from `t` are in the window), try to minimize the window by moving the `left` pointer to the right.
   - Update `windowLen` and `windowStart` if a smaller window is found.
   - Decrement the frequency of the character at the `left` pointer in the `sCount` map.
   - If the frequency of this character in `sCount` becomes less than that in `tCount`, decrement the `formed` count.

6. **Repeating Steps 4 and 5**:
   - Continue expanding and contracting the window until the `right` pointer reaches the end of the string.

7. **Result**:
   - Return the substring of `s` starting from `windowStart` with length `windowLen` as the minimum window substring containing all characters from `t`.

### Example in C++:

```cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> tCount;
        unordered_map<char, int> sCount;

        for (char c : t) tCount[c]++;

        int left = 0, right = 0, required = tCount.size(), formed = 0;
        int windowLen = INT_MAX, windowStart = 0;

        while (right < s.size()) {
            char c = s[right];
            sCount[c]++;

            if (tCount.count(c) && sCount[c] == tCount[c]) formed++;

            while (left <= right && formed == required) {
                c = s[left];
                if (right - left + 1 < windowLen) {
                    windowLen = right - left + 1;
                    windowStart = left;
                }

                sCount[c]--;
                if (tCount.count(c) && sCount[c] < tCount[c]) formed--;

                left++;
            }

            right++;
        }

        return windowLen == INT_MAX ? "" : s.substr(windowStart, windowLen);
    }
};

int main() {
    Solution solution;

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Minimum Window Substring: " << solution.minWindow(s1, t1) << endl;

    string s2 = "a";
    string t2 = "a";
    cout << "Minimum Window Substring: " << solution.minWindow(s2, t2) << endl;

    string s3 = "a";
    string t3 = "aa";
    cout << "Minimum Window Substring: " << solution.minWindow(s3, t3) << endl;

    return 0;
}
```

Output:
```
Minimum Window Substring: BANC
Minimum Window Substring: a
Minimum Window Substring:
```

### Time Complexity:
- The solution uses the sliding window technique, which involves moving both `left` and `right` pointers through the string `s`.
- Each character is processed at most twice (once when expanding and once when contracting the window).
- Thus, the time complexity is O(n), where n is the length of the input string `s`.

### Space Complexity:
- The space complexity is O(k), where k is the number of distinct characters in string `t`.
- This is because the `tCount` and `sCount` maps can store at most `k` distinct characters.
