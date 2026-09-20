class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        // STEP 1: Create an adjacency list.
        // adj[i] will store ALL neighbors directly connected to node i.
        // Example: if 1--2, then adj[1] = {2} and adj[2] = {1}.
        vector<vector<int>> adj(n);


        // STEP 2: Convert the given edge list into an adjacency list.
        // "edges" tells us the connections.
        // "adj" will make those connections easy to traverse during BFS.
        for (auto edge : edges) {

            // edge[0] -> edge[1]
            // Because the graph is UNDIRECTED, we can travel both ways.
            adj[edge[0]].push_back(edge[1]);

            // edge[1] -> edge[0]
            // Add the reverse direction as well.
            adj[edge[1]].push_back(edge[0]);
        }


        // STEP 3: Create visited array.
        // vis[i] = 0  -> node i has NOT been visited.
        // vis[i] = 1  -> node i has already been visited.
        // This prevents us from visiting the same node again and again.
        vector<int> vis(n, 0);


        // STEP 4: We are starting BFS from "source".
        // So mark source as visited BEFORE putting it in the queue.
        vis[source] = 1;


        // STEP 5: BFS uses a QUEUE.
        // Queue = FIFO (First In, First Out).
        // The first node discovered is the first node processed.
        queue<int> Q;


        // Put the starting node into the queue.
        // BFS will begin from here.
        Q.push(source);


        // STEP 6: Keep doing BFS while there are nodes waiting in the queue.
        while (!Q.empty()) {

            // Take the node at the FRONT of the queue.
            // This is the next node BFS wants to process.
            int node = Q.front();

            // Remove that node from the queue.
            Q.pop();


            // STEP 7: Did we reach our destination?
            // If yes, a path exists from source to destination.
            if (node == destination) {
                return true;
            }


            // STEP 8: Look at ALL neighbors of the current node.
            // IMPORTANT:
            // We use adj[node], NOT edges[node].
            // adj[node] = "Who can I directly travel to from this node?"
            for (auto it : adj[node]) {

                // Only visit this neighbor if we haven't visited it before.
                if (!vis[it]) {

                    // Mark it immediately when DISCOVERED.
                    // This prevents the same node from being added to
                    // the queue multiple times.
                    vis[it] = 1;

                    // Add the newly discovered neighbor to the queue.
                    // BFS will process it later.
                    Q.push(it);
                }
            }
        }


        // If the queue became empty, BFS explored everything reachable
        // from source, but destination was never found.
        // Therefore, no path exists.
        return false;
    }
};
