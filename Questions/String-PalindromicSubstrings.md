## Palindromic Substrings

Palindromic substrings are contiguous sequences of characters within a given string that read the same backward as forward. For example, "aba" and "aa" are palindromic substrings within the string "aabaa".

### Concept and Approach:

1. **Odd-Length Palindromes**:
   - To find odd-length palindromic substrings, we consider each character as the center of a potential palindrome and expand outwards while checking if the characters on both sides are equal.
   - For each character at index `i`, we initialize two pointers `left = i` and `right = i`. We keep expanding the `left` pointer to the left and the `right` pointer to the right while checking if the characters at these positions are equal.
   - We increment the count of palindromic substrings for each successful expansion.

2. **Even-Length Palindromes**:
   - To find even-length palindromic substrings, we consider pairs of adjacent characters as potential centers.
   - For each character at index `i`, we consider it as the right center and its left neighbor as the left center. We then expand outwards while checking if the characters on both sides are equal.
   - We increment the count of palindromic substrings for each successful expansion.

3. **Counting Substrings**:
   - We iterate through each character of the input string.
   - For each character, we count the odd-length palindromic substrings and add them to the total count.
   - If the current character is the same as the previous character (for even-length palindromes), we also count the even-length palindromic substrings and add them to the total count.

### Example in C++:

Here's a C++ example implementing the palindromic substring counting algorithm:

```cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countOddLengthPalindromes(int index, string &s) {
        int left = index, right = index, palindromeCount = 0;
        while (left >= 0 && right < s.size()) {
            if (s[left] == s[right]) {
                left--;
                right++;
                palindromeCount++;
            } else {
                break;
            }
        }
        return palindromeCount;
    }

    int countEvenLengthPalindromes(int index, string &s) {
        int left = index - 1, right = index, palindromeCount = 0;
        while (left >= 0 && right < s.size()) {
            if (s[left] == s[right]) {
                left--;
                right++;
                palindromeCount++;
            } else {
                break;
            }
        }
        return palindromeCount;
    }

    int countSubstrings(string s) {
        int totalCount = 0;
        for (int i = 0; i < s.size(); i++) {
            totalCount += countOddLengthPalindromes(i, s);
            if (i != 0 && s[i] == s[i - 1]) {
                totalCount += countEvenLengthPalindromes(i, s);
            }
        }
        return totalCount;
    }
};

int main() {
    Solution solution;
    string s1 = "abc";
    cout << "Number of palindromic substrings in \"" << s1 << "\": " << solution.countSubstrings(s1) << endl;

    string s2 = "aaa";
    cout << "Number of palindromic substrings in \"" << s2 << "\": " << solution.countSubstrings(s2) << endl;

    return 0;
}
```

The output will be:

```
Number of palindromic substrings in "abc": 3
Number of palindromic substrings in "aaa": 6
```

### Time Complexity:
- For each character in the string, we expand both odd and even length palindromes, which takes linear time O(n).
- Total time complexity: O(n^2)

### Space Complexity:
- The additional space used by the algorithm is constant, so space complexity: O(1)