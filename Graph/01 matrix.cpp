
class Solution {
public:
    // Return the shortest distance from every cell to its nearest zero.
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        // Get the number of rows in the input matrix.
        int n = mat.size();

        // Get the number of columns in the input matrix.
        int m = mat[0].size();

        // Create a distance matrix.
        // -1 means the cell has not been visited yet.
        vector<vector<int>> d(n, vector<int>(m, -1));

        // BFS queue stores cell coordinates as {row, column}.
        queue<pair<int, int>> Q;

        // Scan every row to find all zero cells.
        for (int i = 0; i < n; i++) {

            // Scan every column in the current row.
            for (int j = 0; j < m; j++) {

                // Every zero is a starting point for BFS.
                if (mat[i][j] == 0) {

                    // Add this zero cell to the BFS queue.
                    Q.push({i, j});

                    // A zero is zero steps away from the nearest zero.
                    d[i][j] = 0;
                }
            }
        }

        // Row changes: down, up, stay, stay.
        vector<int> r = {1, -1, 0, 0};

        // Column changes: stay, stay, left, right.
        // Together, r and c represent the four directions.
        vector<int> c = {0, 0, -1, 1};

        // Continue while there are cells waiting to be explored.
        while (!Q.empty()) {

            // Read the row of the cell at the front of the queue.
            int rs = Q.front().first;

            // Read the column of the cell at the front of the queue.
            int cs = Q.front().second;

            // Remove this cell because we are now processing it.
            Q.pop();

            // Try all four directions from the current cell.
            for (int i = 0; i < 4; i++) {

                // Calculate the neighbor's row.
                int nr = rs + r[i];

                // Calculate the neighbor's column.
                int nc = cs + c[i];

                // Check that the neighbor is inside the matrix
                // and has not been visited yet.
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    d[nr][nc] == -1) {

                    // The neighbor is one step farther from zero
                    // than the current cell.
                    d[nr][nc] = d[rs][cs] + 1;

                    // Add the discovered neighbor to explore later.
                    Q.push({nr, nc});
                }
            }
        }

        // Return the matrix containing all shortest distances.
        return d;
    }
};
