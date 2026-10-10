```cpp
class Solution {
public:

    // DFS: Visit a city and all cities connected to it.
    // node = current city we are exploring.
    // adj = adjacency list containing each city's neighbors.
    // vis = visited array shared across all DFS calls.
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {

        // BASE CASE:
        // If this city has already been visited, stop this call.
        // This prevents infinite recursion when the graph has cycles.
        if (vis[node] == 1) {
            return;
        }

        // Mark the current city as visited BEFORE exploring neighbors.
        // This prevents DFS from visiting the same city repeatedly.
        vis[node] = 1;

        // Visit every neighbor connected to the current city.
        for (auto it : adj[node]) {

            // Recursively explore this neighbor and its connected cities.
            // The same adj and vis are shared with every recursive call.
            dfs(it, adj, vis);
        }

        // Once all neighbors are explored, this DFS call finishes.
    }

    // LeetCode calls this function to count the number of provinces.
    int findCircleNum(vector<vector<int>>& isConnected) {

        // n = total number of cities.
        // The matrix has n rows and n columns.
        int n = isConnected.size();

        // Create an empty adjacency list for each city.
        // adj[i] will store the cities directly connected to city i.
        vector<vector<int>> adj(n);

        // Outer loop: choose each city as the starting row.
        for (int i = 0; i < n; i++) {

            // Inner loop: check its connection to every city j.
            for (int j = 0; j < n; j++) {

                // isConnected[i][j] == 1 means cities i and j are connected.
                // i != j skips a city's connection to itself.
                if (isConnected[i][j] == 1 && i != j) {

                    // Add city j to city i's neighbor list.
                    // Because the matrix is symmetric, both directions
                    // will be added when the loops check the reverse pair.
                    adj[i].push_back(j);
                }
            }
        }

        // Initially, every city is unvisited (0).
        // A value of 1 means the city has been visited by DFS.
        vector<int> vis(n, 0);

        // cnt stores the number of separate provinces found so far.
        int cnt = 0;

        // Check every city to find any unvisited connected component.
        for (int i = 0; i < n; i++) {

            // If city i is unvisited, it belongs to a new province.
            if (vis[i] == 0) {

                // Count this new province BEFORE exploring it.
                cnt++;

                // Explore and mark every city connected to city i.
                // Those cities will be skipped by the outer loop later.
                dfs(i, adj, vis);
            }
        }

        // Return the total number of provinces discovered.
        return cnt;
    }
};
```
