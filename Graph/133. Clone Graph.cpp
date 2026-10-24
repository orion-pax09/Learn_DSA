/*
    LEETCODE 133: CLONE GRAPH

    GOAL:
    Create a completely separate copy of a graph.

    IMPORTANT:
    Original nodes must remain unchanged.
    Each cloned node must connect to cloned neighbors,
    NOT to the original neighbors.

    MAIN IDEA:
    DFS + Hash Map

    The map stores:
    original node pointer -> cloned node pointer

    Example:
    Original Node 1 -> Clone Node 1
    Original Node 2 -> Clone Node 2
*/

class Solution {
public:

    /*
        DFS HELPER FUNCTION

        node = the original node we are currently visiting

        mp = map that remembers which original nodes
             have already been cloned

        RETURNS:
        A pointer to the clone of the given original node.
    */
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {

        // STEP 1: BASE CASE
        // If the input node is nullptr, there is no node to clone.
        // Return nullptr to stop processing this empty node.
        if (node == nullptr) {
            return nullptr;
        }

        // STEP 2: CHECK WHETHER THIS NODE WAS ALREADY CLONED
        // mp.find(node) searches the map using the ORIGINAL node pointer.
        // If the node exists in the map, its clone already exists.
        //
        // Why is this necessary?
        // Graphs can contain cycles and multiple paths to the same node.
        // Without this check, DFS could keep visiting nodes forever.
        if (mp.find(node) != mp.end()) {

            // Return the existing clone instead of creating a duplicate.
            return mp[node];
        }

        // STEP 3: CREATE A COPY OF THE CURRENT NODE
        // Copy the original node's value into a NEW Node object.
        //
        // Example:
        // Original node has val = 1.
        // clone is a different object whose val is also 1.
        //
        // Only the value is copied here.
        // The neighbors will be connected later.
        Node* clone = new Node(node->val);

        // STEP 4: SAVE THE CLONE IN THE MAP
        // Key   = original node pointer (node)
        // Value = cloned node pointer (clone)
        //
        // We MUST do this BEFORE exploring neighbors.
        // A neighbor may lead back to the current node.
        // The map lets DFS recognize it and reuse this clone.
        mp[node] = clone;

        // STEP 5: VISIT EVERY NEIGHBOR OF THE ORIGINAL NODE
        // node->neighbors contains pointers to ORIGINAL neighbors.
        //
        // The loop takes one original neighbor at a time.
        for (Node* neighbour : node->neighbors) {

            // STEP 6: CLONE THE NEIGHBOR
            // Recursively call DFS for this original neighbor.
            //
            // If the neighbor is not in the map:
            //     DFS creates its clone and stores it.
            //
            // If the neighbor is already in the map:
            //     DFS returns its existing clone.
            //
            // cloned is a pointer to the CLONED neighbor,
            // not the original neighbor.
            Node* cloned = dfs(neighbour, mp);

            // STEP 7: CONNECT THE CLONED NODES
            // Add the cloned neighbor to this clone's neighbors vector.
            //
            // push_back() adds one element to the vector.
            //
            // We use 'cloned', NOT 'neighbour',
            // because the new graph must connect only cloned nodes.
            clone->neighbors.push_back(cloned);
        }

        // STEP 8: RETURN THE COMPLETED CLONE
        // All neighbors of this node have now been processed.
        // Return this clone to the recursive caller.
        //
        // IMPORTANT:
        // Returning does NOT delete the node or remove it from the map.
        return clone;
    }


    // MAIN FUNCTION: LeetCode calls cloneGraph() with the starting node.
    Node* cloneGraph(Node* node) {

        // STEP 1: HANDLE AN EMPTY GRAPH
        // If there is no starting node, return nullptr.
        if (node == nullptr) {
            return nullptr;
        }

        // STEP 2: CREATE THE VISITED / CLONE MAP
        // Initially, no original nodes have been cloned.
        //
        // Node* keys identify original node objects.
        // Node* values point to their corresponding clone objects.
        //
        // The map is shared by every recursive DFS call.
        unordered_map<Node*, Node*> mp;

        // STEP 3: START DFS FROM THE GIVEN NODE
        // DFS will clone the starting node and recursively explore
        // every node reachable from it.
        //
        // Return the clone of the starting node as the final answer.
        return dfs(node, mp);
    }
};
