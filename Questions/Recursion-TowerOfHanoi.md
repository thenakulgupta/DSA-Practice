## Tower of Hanoi

The Tower of Hanoi is a classic puzzle that involves moving a stack of disks from one tower to another, following certain rules. The puzzle is based on three rods (towers) and a set of disks with different sizes that can slide onto any tower. The objective is to move the entire stack of disks from the first tower to the third tower while adhering to the following rules:

1. Only one disk can be moved at a time.
2. A disk can be slid off the top of one tower onto another tower.
3. A disk cannot be placed on top of a smaller disk.

The task is to write a program that solves the Tower of Hanoi puzzle using a stack-based approach.

### Concept and Approach:

1. **Recursion and Divide-and-Conquer**:
   - The Tower of Hanoi problem can be elegantly solved using recursion and divide-and-conquer strategy.
   - If there's only one disk to move, you can directly move it to the destination tower.
   - If there are more than one disk, you can follow these steps:
     - Move the top (n-1) disks from the source tower to the auxiliary tower using the destination tower as the auxiliary.
     - Move the nth disk from the source tower to the destination tower.
     - Move the (n-1) disks from the auxiliary tower to the destination tower using the source tower as the auxiliary.

2. **Implementing the Recursive Solution**:
   - Create a recursive function `towerOfHanoiHelper` that takes the number of disks `n`, source rod, destination rod, and auxiliary rod as parameters.
   - Base case: If `n` is 1, directly move the disk from the source rod to the destination rod.
   - Recursive step: Follow the divide-and-conquer approach as mentioned above.

3. **Printing the Steps**:
   - In the `towerOfHanoiHelper` function, before and after each recursive call, print the step indicating the movement of disks.

### Example in C++:

Here's a C++ example illustrating the Tower of Hanoi problem and its solution:

```cpp
#include <iostream>
using namespace std;

void towerOfHanoiHelper(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk " << n << " from '" << source << "' to '" << destination << "'" << endl;
        return;
    }
    
    towerOfHanoiHelper(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from '" << source << "' to '" << destination << "'" << endl;
    towerOfHanoiHelper(n - 1, auxiliary, destination, source);
}

void towerOfHanoi(int n) {
    towerOfHanoiHelper(n, 'A', 'C', 'B');
}

int main() {
    int numDisks = 3;
    towerOfHanoi(numDisks);
    return 0;
}
```

The output will be:

```
Move disk 1 from 'A' to 'C'
Move disk 2 from 'A' to 'B'
Move disk 1 from 'C' to 'B'
Move disk 3 from 'A' to 'C'
Move disk 1 from 'B' to 'A'
Move disk 2 from 'B' to 'C'
Move disk 1 from 'A' to 'C'
```

### Time Complexity:
- The time complexity of the Tower of Hanoi algorithm is exponential, specifically O(2^n), where n is the number of disks.

### Space Complexity:
- The space complexity is determined by the maximum depth of the recursion stack, which is proportional to the number of disks. The space complexity is O(n).