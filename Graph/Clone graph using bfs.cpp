class Solution {
public:
    Node* cloneGraph(Node* node) {

        // Step 1: If the graph is empty, return nullptr.
        if (node == nullptr) {
            return nullptr;
        }

        // Step 2: Map each original node to its clone.
        unordered_map<Node*, Node*> mp;

        // Step 3: Create the clone of the starting node.
        Node* clone = new Node(node->val);

        // Remember the original node and its clone.
        mp[node] = clone;

        // Step 4: Create a queue for BFS.
        queue<Node*> q;

        // Start BFS from the original starting node.
        q.push(node);

        // Step 5: Process nodes while the queue is not empty.
        while (!q.empty()) {

            // Get the next original node to process.
            Node* curr = q.front();
            q.pop();

            // Step 6: Visit every neighbor of the current node.
            for (Node* neighbor : curr->neighbors) {

                // If this neighbor has not been cloned yet...
                if (mp.find(neighbor) == mp.end()) {

                    // Create its clone.
                    mp[neighbor] = new Node(neighbor->val);

                    // Schedule the original neighbor for BFS.
                    q.push(neighbor);
                }

                // Connect the current clone to the neighbor's clone.
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        // Step 7: Return the clone of the starting node.
        return clone;
    }
};
