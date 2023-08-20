## The Game of Life

The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a simulation of cellular evolution using a grid of cells, each of which can be in one of two states: alive (1) or dead (0). The game proceeds in discrete time steps, and the state of each cell in the next generation is determined by its current state and the states of its eight neighbors according to a set of rules.

### Rules of the Game:

1. **Underpopulation**: Any live cell with fewer than two live neighbors dies as if caused by under-population.
2. **Survival**: Any live cell with two or three live neighbors lives on to the next generation.
3. **Overpopulation**: Any live cell with more than three live neighbors dies, as if by over-population.
4. **Reproduction**: Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

### Approach:

1. **Neighbour Checking**: For each cell in the grid, determine the number of live neighbors it has. This is done by checking the surrounding eight cells (horizontal, vertical, and diagonal) and counting the number of live cells among them.

2. **Updating States**: Using the live neighbor count and the current state of each cell, apply the rules of the game. Mark cells to be modified as "newly alive" (2) or "newly dead" (3) if they need to change state in the next generation.

3. **Finalizing the Changes**: After calculating the new states for all cells, iterate through the grid again and replace the "newly alive" (2) cells with "alive" (1) and the "newly dead" (3) cells with "dead" (0), effectively updating the grid for the next generation.

4. **Boundary Checks**: Ensure that neighbor checks are performed within the bounds of the grid to avoid accessing invalid indices.

### C++ Code Example:

Here's a C++ example illustrating the implementation of the Game of Life:

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int posRow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int posCol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    bool isSafe(int m, int n, int row, int col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
    
    int getLiveNeighbors(vector<vector<int>>& board, int m, int n, int i, int j) {
        int liveNeighbors = 0;
        for (int k = 0; k < 8; ++k) {
            int newRow = posRow[k] + i;
            int newCol = posCol[k] + j;
            if (isSafe(m, n, newRow, newCol)) {
                if (board[newRow][newCol] == 1 || board[newRow][newCol] == 3) {
                    liveNeighbors++;
                }
            }
        }
        return liveNeighbors;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = getLiveNeighbors(board, m, n, i, j);
                if (board[i][j] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = 3;
                    }
                } else if (board[i][j] == 0) {
                    if (liveNeighbors == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == 3) {
                    board[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution solution;

    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    solution.gameOfLife(board);

    cout << "Next generation:" << endl;
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### Output:

```
Next generation:
0 0 0 
1 0 1 
0 1 1 
0 1 0 
```

### Time and Space Complexity:

- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
- Space Complexity: O(1), as the additional space used is constant regardless of the input size.