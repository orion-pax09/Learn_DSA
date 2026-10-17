
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // Queue stores {{row, column}, time}.
        // BFS processes rotten oranges in increasing order of time.
        queue<pair<pair<int, int>, int>> Q;

        // Get the number of rows and columns in the grid.
        int n = grid.size();
        int m = grid[0].size();

        // Stores the maximum time needed to rot reachable oranges.
        int maxTime = 0;

        // Counts fresh oranges that have not rotted yet.
        int fresh = 0;

        // Scan the entire grid to prepare for multi-source BFS.
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                // Every initially rotten orange is a BFS starting point.
                // Its time is 0 because it is already rotten.
                if (grid[i][j] == 2) {
                    Q.push({{i, j}, 0});
                }

                // Count fresh oranges so we can detect unreachable ones.
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Row offsets: down, up, same row, same row.
        vector<int> rs = {1, -1, 0, 0};

        // Column offsets: same column, same column, left, right.
        // Together, rs and cs represent the four adjacent directions.
        vector<int> cs = {0, 0, -1, 1};

        // Continue BFS while there are oranges waiting to be processed.
        while (!Q.empty()) {

            // Read the row, column, and time of the front queue item.
            int rows = Q.front().first.first;
            int cols = Q.front().first.second;
            int t = Q.front().second;

            // Remove this orange from the front of the queue.
            Q.pop();

            // Track the greatest time reached during BFS.
            maxTime = max(maxTime, t);

            // Check all four neighbors of the current orange.
            for (int i = 0; i < 4; i++) {

                // Calculate the neighboring column.
                int nc = cs[i] + cols;

                // Calculate the neighboring row.
                int nr = rs[i] + rows;

                // First check boundaries to avoid accessing invalid cells.
                // Then check whether the neighbor is a fresh orange.
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == 1) {

                    // Mark it rotten immediately so it cannot be
                    // added to the queue again from another neighbor.
                    grid[nr][nc] = 2;

                    // One fewer fresh orange remains.
                    fresh--;

                    // It rots one minute after the current orange.
                    Q.push({{nr, nc}, t + 1});
                }
            }
        }

        // If fresh oranges remain, some were unreachable.
        if (fresh > 0) {
            return -1;
        }

        // All oranges have rotted; return the total time required.
        return maxTime;
    }
};
