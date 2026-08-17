int equalPairs(vector<vector<int>>& grid) {

    int count = 0;  
    // This will store the total number of equal row-column pairs.

    map<vector<int>, int> rows;
    // Key   = a complete row, e.g. [2,4,2,2]
    // Value = how many times that row appears.

    map<vector<int>, int> column;
    // Key   = a complete column.
    // Value = how many times that column appears.


    for (int i = 0; i < grid.size(); i++) {
        // Go through every row.

        rows[grid[i]]++;
        // grid[i] gives the entire row.
        // Store that row as the KEY.
        // ++ increases its frequency.
        //
        // Example:
        // [2,4,2,2] → 1
        // If we see it again:
        // [2,4,2,2] → 2
    }


    for (int i = 0; i < grid.size(); i++) {
        // i represents the COLUMN we are currently building.

        vector<int> cols;
        // Temporary vector that will store one complete column.


        for (int j = 0; j < grid.size(); j++) {
            // j goes through every ROW.

            cols.push_back(grid[j][i]);
            // grid[j][i]:
            // j = row
            // i = column
            //
            // We keep i fixed and change j,
            // so we move DOWN the column.
        }


        column[cols]++;
        // Store the complete column as the KEY.
        // Increase its frequency.
        //
        // Example:
        // [2,4,2,2] → 1
    }


    for (auto r : rows) {
        // Go through every row stored in the map.
        //
        // r.first  = the row vector (KEY)
        // r.second = how many times that row appears (VALUE)


        if (column.find(r.first) != column.end()) {
            // Check whether this row vector also exists
            // as a KEY in the column map.
            //
            // If it exists, we found a matching row and column.


            count += r.second * column[r.first];
            // r.second = number of matching ROWS
            // column[r.first] = number of matching COLUMNS
            //
            // Multiply them because every matching row
            // can pair with every matching column.
        }
    }


    return count;
    // Return the total number of equal row-column pairs.
}
