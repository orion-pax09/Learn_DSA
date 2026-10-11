
#include <iostream>  // Provides cout for printing output
#include <vector>    // Provides the vector container
#include <queue>     // Provides the queue used in BFS
using namespace std; // Avoids writing std:: before standard library names

class Solution {
public:

    // BFS explores all land cells connected to the starting cell.
    void BFS(int r, int c,
             vector<vector<int>>& vis,
             vector<vector<char>>& grid) {

        int n = grid.size();       // Total number of rows
        int m = grid[0].size();    // Total number of columns

        // Direction arrays: up, down, left, right
        vector<int> dr = {-1, 1, 0, 0}; // Row movement
        vector<int> dc = {0, 0, -1, 1}; // Column movement

        queue<pair<int, int>> Q; // Queue stores cell coordinates (row, col)

        Q.push({r, c});   // Add the starting land cell to the queue
        vis[r][c] = 1;    // Mark it visited immediately to prevent duplicates

        // Continue until every reachable land cell has been explored
        while (!Q.empty()) {

            int rows = Q.front().first;  // Get the front cell's row
            int cols = Q.front().second; // Get the front cell's column

            Q.pop(); // Remove the current cell from the queue

            // Check all four neighboring directions
            for (int i = 0; i < 4; i++) {

                // Calculate the neighboring cell's row
                int nrows = rows + dr[i];

                // Calculate the neighboring cell's column
                int ncols = cols + dc[i];

                // Check that the neighbor is inside the grid,
                // has not been visited, and contains land ('1')
                if (nrows >= 0 && nrows < n &&
                    ncols >= 0 && ncols < m &&
                    !vis[nrows][ncols] &&
                    grid[nrows][ncols] == '1') {

                    vis[nrows][ncols] = 1; // Mark neighbor visited
                    Q.push({nrows, ncols}); // Add neighbor for later exploration
                }
            }
        }
        // When the queue is empty, this entire island is explored.
    }

    // Counts how many separate islands exist in the grid.
    int numIslands(vector<vector<char>>& grid) {

        // If the grid has no rows or columns, there are no islands.
        if (grid.empty() || grid[0].empty())
            return 0;

        int n = grid.size();      // Number of rows
        int m = grid[0].size();   // Number of columns

        // Create a visited matrix: 0 = unvisited, 1 = visited.
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0; // Stores the total number of islands

        // Visit every row in the grid
        for (int i = 0; i < n; i++) {

            // Visit every column in the current row
            for (int j = 0; j < m; j++) {

                // If this cell is unvisited land, a new island is found.
                if (grid[i][j] == '1' && vis[i][j] == 0) {

                    cnt++; // Count this new island exactly once

                    // Explore and mark every cell connected to this island.
                    BFS(i, j, vis, grid);
                }
            }
        }

        return cnt; // Return the total number of separate islands
    }
};

int main() {

    // Example grid: '1' means land, '0' means water.
    vector<vector<char>> input = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    Solution s; // Create an object of the Solution class

    // Run the function and print the number of islands
    cout << s.numIslands(input) << endl;

    return 0; // End the program successfully
}
