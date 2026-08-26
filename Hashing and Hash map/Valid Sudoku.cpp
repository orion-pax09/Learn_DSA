class Solution {
public:

    // =========================================================
    // CHECK ALL 9 ROWS
    // =========================================================
    bool checkrows(vector<vector<char>>& board) {

        // Go through each row one by one
        for (int i = 0; i < board.size(); i++) {

            // New map for every row
            // This means each row is checked independently
            unordered_map<char, int> rows;

            // Go through every cell in the current row
            for (int j = 0; j < board.size(); j++) {

                // '.' means empty cell, so ignore it
                if (board[i][j] == '.') {
                    continue;
                }

                // If this number already exists in the row
                // then we found a duplicate
                if (rows.count(board[i][j])) {
                    return false;
                }

                // Store the number as "seen"
                // Next time we see it, count() will find it
                rows[board[i][j]]++;
            }
        }

        // No duplicate was found in any row
        return true;
    }


    // =========================================================
    // CHECK ALL 9 COLUMNS
    // =========================================================
    bool checkcols(vector<vector<char>>& board) {

        // Go through each column one by one
        for (int i = 0; i < board.size(); i++) {

            // New map for every column
            // Each column is checked independently
            unordered_map<char, int> cols;

            // Move down through the current column
            for (int j = 0; j < board.size(); j++) {

                // '.' means empty cell, so ignore it
                if (board[j][i] == '.') {
                    continue;
                }

                // If this number already exists in the column
                // then we found a duplicate
                if (cols.count(board[j][i])) {
                    return false;
                }

                // Store the number as "seen"
                cols[board[j][i]] = j;
            }
        }

        // No duplicate was found in any column
        return true;
    }


    // =========================================================
    // CHECK ALL 9 GRIDS (3 x 3 BOXES)
    // =========================================================
    bool checkgrid(vector<vector<char>>& board) {

        // rows moves by 3:
        // 0, 3, 6
        // These are the starting rows of each 3x3 box
        for (int rows = 0; rows < 9; rows += 3) {

            // cols moves by 3:
            // 0, 3, 6
            // These are the starting columns of each 3x3 box
            for (int cols = 0; cols < 9; cols += 3) {

                // New map for every 3x3 grid
                unordered_map<char, int> grid;

                // Check 3 rows of the current grid
                // Example: if rows = 3, check rows 3, 4, 5
                for (int i = rows; i < rows + 3; i++) {

                    // Check 3 columns of the current grid
                    // Example: if cols = 3, check cols 3, 4, 5
                    for (int j = cols; j < cols + 3; j++) {

                        // '.' means empty cell, so ignore it
                        if (board[i][j] == '.') {
                            continue;
                        }

                        // If number already exists in this 3x3 grid
                        // then we found a duplicate
                        if (grid.count(board[i][j])) {
                            return false;
                        }

                        // Store the number as "seen"
                        grid[board[i][j]] = j;
                    }
                }
            }
        }

        // No duplicate was found in any 3x3 grid
        return true;
    }


    // =========================================================
    // MAIN FUNCTION
    // =========================================================
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check whether every row is valid
        bool rows = checkrows(board);

        // Check whether every column is valid
        bool cols = checkcols(board);

        // Check whether every 3x3 grid is valid
        bool grid = checkgrid(board);

        // Sudoku is valid only if ALL THREE are valid
        if (rows && cols && grid) {
            return true;
        }

        // At least one check failed
        return false;
    }
};
