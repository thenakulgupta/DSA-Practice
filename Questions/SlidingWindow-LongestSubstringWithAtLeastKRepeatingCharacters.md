## Longest Substring with At Least K Repeating Characters

The problem is to find the length of the longest substring in a given string `s` such that the frequency of each character in this substring is greater than or equal to `k`.

### Concept and Approach:

1. **Sliding Window Technique**: This problem can be solved using the sliding window technique, where you maintain a window of characters and slide it across the string while keeping track of the frequency of characters within the window.

2. **Character Frequency Count**: We'll use an array `count` to keep track of the frequency of characters in the current window. The array's size will be 26 (for lowercase English letters). Each index represents a character ('a' to 'z'), and the value at that index represents the frequency of that character within the current window.

3. **Maintain Valid Substrings**: While sliding the window, we'll keep track of the number of unique characters in the window (`uniqChars`) and the number of characters that have a frequency of at least `k` (`noOfKMatched`).

4. **Expanding and Shrinking Window**:
   - We'll initially expand the window by incrementing `j` until the number of unique characters (`uniqChars`) is less than or equal to the maximum number of unique characters we're considering (`ch`).
   - If the number of unique characters exceeds the limit, we'll shrink the window by incrementing `i` and decrementing the frequency count of characters in the current window.

5. **Update Maximum Length**: Whenever the number of unique characters (`uniqChars`) and the number of characters with a frequency of at least `k` (`noOfKMatched`) are equal to the maximum unique characters we're considering (`ch`), we'll update the maximum length of valid substrings (`ans`) as `max(ans, j - i)`.

### Example in C++:

Here's a C++ example illustrating the approach:

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestSubstring(string s, int k) {
    int ans = 0;
    int n = s.length();
    
    for (int ch = 1; ch <= 26; ++ch) {
        vector<int> count(26, 0);
        int i = 0, j = 0, uniqChars = 0, noOfKMatched = 0;
        
        while (j < n) {
            if (uniqChars <= ch) {
                int c = s[j] - 'a';
                if (count[c] == 0) uniqChars++;
                count[c]++;
                if (count[c] == k) noOfKMatched++;
                j++;
            } else {
                int c = s[i] - 'a';
                if (count[c] == k) noOfKMatched--;
                count[c]--;
                if (count[c] == 0) uniqChars--;
                i++;
            }
            
            if (uniqChars == noOfKMatched && uniqChars == ch) {
                ans = max(ans, j - i);
            }
        }
    }
    
    return ans;
}

int main() {
    string s1 = "aaabb";
    int k1 = 3;
    cout << "Longest substring length for \"" << s1 << "\" and k = " << k1 << ": " << longestSubstring(s1, k1) << endl;

    string s2 = "ababbc";
    int k2 = 2;
    cout << "Longest substring length for \"" << s2 << "\" and k = " << k2 << ": " << longestSubstring(s2, k2) << endl;

    return 0;
}
```

Output:

```
Longest substring length for "aaabb" and k = 3: 3
Longest substring length for "ababbc" and k = 2: 5
```

### Time Complexity:
- The algorithm uses a sliding window approach and iterates through the string once. Each character is processed at most twice (when added to the window and when removed from the window). Since the alphabet has a constant number of characters (26), the time complexity is O(26 * n), which simplifies to O(n).

### Space Complexity:
- The additional space used is for the `count` array, which has a fixed size of 26 (constant). Therefore, the space complexity is O(1).