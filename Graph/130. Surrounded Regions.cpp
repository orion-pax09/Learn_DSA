
#include <iostream>   // Provides standard input/output features
#include <queue>      // Provides queue for BFS
#include <vector>     // Provides the vector container
using namespace std;  // Lets us write vector instead of std::vector

class Solution {
public:

    // BFS explores all 'O' cells connected to a starting cell
    void bfs(vector<vector<char>>& board,
             int u, int x,
             vector<vector<int>>& vis) {

        int n = board.size();       // Number of rows
        int m = board[0].size();    // Number of columns

        // Row changes: down, up, stay, stay
        vector<int> rs = {1, -1, 0, 0};

        // Column changes: stay, stay, left, right
        vector<int> js = {0, 0, -1, 1};

        queue<pair<int, int>> Q;    // Stores cell coordinates (row, col)

        Q.push({u, x});             // Add the starting boundary 'O' to queue
        vis[u][x] = 1;              // Mark starting cell as visited

        // Continue while there are cells waiting to be explored
        while (!Q.empty()) {

            int s = Q.front().first;  // Get current cell's row
            int c = Q.front().second; // Get current cell's column

            Q.pop();                  // Remove current cell from queue

            // Check all four neighboring cells
            for (int i = 0; i < 4; i++) {

                int row = rs[i] + s;   // Neighbor's row
                int cols = js[i] + c;  // Neighbor's column

                // Check neighbor is inside board, contains 'O',
                // and has not been visited
                if (row >= 0 && row < n &&
                    cols >= 0 && cols < m &&
                    board[row][cols] == 'O' &&
                    vis[row][cols] == 0) {

                    vis[row][cols] = 1;       // Mark before enqueueing
                    Q.push({row, cols});      // Explore this cell later
                }
            }
        }
    }

    // Main function called by LeetCode
    void solve(vector<vector<char>>& board) {

        int n = board.size();       // Get number of rows
        int m = board[0].size();    // Get number of columns

        // One shared visited matrix for the entire board
        // Initially, 0 means unvisited; 1 means visited
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Examine every cell to find boundary cells
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                // Is this cell on any edge of the board?
                // If it is also 'O', it cannot be captured
                if ((i == 0 || i == n - 1 ||
                     j == 0 || j == m - 1) &&
                    board[i][j] == 'O') {

                    // Explore all 'O' cells connected to this boundary cell
                    bfs(board, i, j, vis);
                }
            }
        }

        // Examine every cell again to capture surrounded regions
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                // An 'O' not reached from any boundary 'O' is surrounded
                if (board[i][j] == 'O' && vis[i][j] == 0) {

                    board[i][j] = 'X';  // Capture the surrounded cell
                }
            }
        }
    }
};
