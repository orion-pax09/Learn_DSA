/* 
// Definition for a Node. 
class Node { 
public: 
    int val;        // Stores the value of the node.
    Node* prev;     // Points to the previous node.
    Node* next;     // Points to the next node.
    Node* child;    // Points to another doubly linked list (if it has one).
}; 
*/ 
 
class Solution { 
public: 
    Node* flatten(Node* head) { 

        // Start from the first node of the main doubly linked list.
        Node* curr = head; 

        // Keep moving through the list until there are no more nodes.
        while(curr != nullptr){ 

            // IMPORTANT:
            // Save the original next node BEFORE changing curr->next.
            //
            // Example:
            //     3 -> 4
            //     curr = 3
            //     curr_next = 4
            //
            // We save 4 because later the child list must connect back to it.
            Node* curr_next = curr->next; 

            // Check whether the current node has a child list.
            if (curr->child != nullptr){ 

                // Recursively flatten the child list.
                //
                // 'Next' will point to the HEAD of the flattened child list.
                //
                // Example:
                //     3
                //     |
                //     7 -> 8
                //
                // Next = 7
                Node* Next = flatten(curr->child); 

                // Connect the current node to the HEAD of the child list.
                //
                // Before:
                //     3 -> 4
                //     |
                //     7 -> 8
                //
                // After:
                //     3 -> 7
                curr->next = Next; 

                // Because this is a DOUBLY linked list,
                // also connect the child head backwards to curr.
                //
                //     3 <-> 7
                curr->next->prev = curr; 

                // The child list has now been inserted into the main list,
                // so remove the child pointer.
                //
                // We don't want:
                //     3 --child--> 7
                //
                // We want everything connected through next/prev.
                curr->child = nullptr; 

                // Start at the HEAD of the flattened child list.
                //
                // Next = 7
                // tail = 7 initially.
                //
                // We will move tail forward until we reach the LAST
                // node of the child list.
                Node* tail = Next; 

                // Move tail forward until there is no next node.
                //
                // Example:
                //     7 -> 8 -> 9 -> nullptr
                //
                // tail starts at 7
                // tail moves to 8
                // tail moves to 9
                // tail stops because 9->next == nullptr
                while(tail->next != nullptr){ 

                    // Move tail one node forward.
                    tail = tail->next; 
                } 

                // Connect the TAIL of the child list to the
                // original next node that we saved earlier.
                //
                // Example:
                //     curr = 3
                //     curr_next = 4
                //     child = 7 -> 8
                //
                // We now make:
                //
                //     3 -> 7 -> 8 -> 4
                tail->next = curr_next; 

                // Only connect backwards if curr_next actually exists.
                //
                // If curr_next == nullptr, there is no node after
                // the child list, so there is nothing to connect back to.
                if (curr_next != nullptr){ 

                    // Complete the backwards connection.
                    //
                    //     8 -> 4
                    //     8 <- 4
                    //
                    // So:
                    //     8 <-> 4
                    curr_next->prev = tail; 
                } 
            } 

            // Move curr to the next node.
            //
            // If we inserted a child list, this moves into that
            // flattened child list.
            //
            // Eventually it reaches curr_next and continues
            // through the original main list.
            curr = curr->next; 
        } 

        // Return the HEAD of the completely flattened list.
        return head; 
    } 
};
