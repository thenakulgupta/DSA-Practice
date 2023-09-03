## Book Allocation Problem

The Book Allocation Problem aims to distribute a set of books among a certain number of students in such a way that the maximum number of pages any student has to read is minimized. Each book has a certain number of pages, and we must allocate the books to the students in consecutive order.

### Concept and Approach:

To solve the Book Allocation Problem, we can make use of Binary Search and a validation function (`isPossible`). The general idea is to minimize the maximum number of pages read by any student while ensuring all books are allocated.

Here's the step-by-step approach:

1. **Binary Search Initialization**:
    - Initialize `st` and `en` for binary search. `st` starts from 0 and `en` starts from the sum of all pages across all books.
  
2. **Binary Search Iteration**:
    - Calculate the middle value (`mid`) of the search range `st` and `en`.
    - Use the `isPossible` function to determine whether it's feasible to allocate books in a way where no student reads more than `mid` pages.
  
3. **Validation (`isPossible`) Function**:
    - Initialize a counter `studentCount` starting from 1 and a variable `pageSum` starting from 0.
    - Traverse through each book, adding its number of pages to `pageSum`.
    - If at any point `pageSum` crosses `mid`, increment `studentCount` and reset `pageSum`.
    - If `studentCount` crosses the number of students available, or any book has more pages than `mid`, return `False`.
  
4. **Recursive Function Call (`getMinBookPages`)**:
    - Based on the feasibility test (`isPossible`), adjust the search range for the binary search and recursively search for the optimal solution.

5. **Final Output**:
    - The answer will be the value of `mid` where the binary search terminates.

### Python Example:

Here's a code snippet explaining this in Python.

```python
# Importing required modules
from typing import List

# Solution class
class Solution:
    # Function to validate if a particular division is feasible
    def isPossible(self, arr: List[int], books: int, students: int, mid: int) -> bool:
        studentCount = 1  # Initial student count
        pageSum = 0  # Initial sum of pages
        
        # Loop through each book
        for i in range(books):
            pageSum += arr[i]
            
            # If sum of pages crosses mid, allocate to next student
            if pageSum > mid:
                pageSum = arr[i]
                studentCount += 1
                
                # Return False if more students are needed than available
                if studentCount > students or arr[i] > mid:
                    return False
        
        return True

    # Main function to get minimum number of book pages
    def getMinBookPages(self, arr: List[int], books: int, students: int, st: int, en: int) -> int:
        if st > en:
            return st
        
        mid = st + (en - st) // 2
        if self.isPossible(arr, books, students, mid):
            return self.getMinBookPages(arr, books, students, st, mid - 1)
        else:
            return self.getMinBookPages(arr, books, students, mid + 1, en)

# Main function
def main():
    arr = [147, 73, 265, 305, 191, 152, 192, 293, 309, 292, 182, 157, 381, 287, 73, 162, 313, 366, 346, 47]
    students = 10
    books = len(arr)
    st = 0
    en = sum(arr)
    
    minBookPages = Solution().getMinBookPages(arr, books, students, st, en)
    print(minBookPages)

if __name__ == "__main__":
    main()
```

### Output:

```text
602
```

### Time Complexity:

- Time complexity for the `isPossible` function is `(O(n))`, where "n" is the number of books.
- The binary search iteration runs in `O(log(sum of all pages in books))`.
  
Therefore, the overall time complexity would be `O(n log Sum)`.

### Space Complexity:

- No additional data structures are used that scale with input size.
- The recursion stack for the binary search will go up to `O(logn)`.

So, the space complexity is `O(logn)`.