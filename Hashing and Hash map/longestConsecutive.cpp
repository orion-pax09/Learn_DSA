class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Stores the longest consecutive sequence found so far.
        // Start with 1 because a single number itself is a sequence of length 1.
        int longest = 1;

        // HashSet: stores every number.
        // Main purpose: quickly check whether a number exists.
        unordered_set<int> st;

        // If the array is empty, there is no consecutive sequence.
        if (nums.size() == 0) {
            return 0;
        }

        // Put every number from nums into the HashSet.
        // We don't care about indexes — we only care whether a number EXISTS.
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        // Look at every unique number in the HashSet.
        for (auto it : st) {

            // Get the number immediately BEFORE the current number.
            // Example: if it = 5, x = 4.
            int x = it - 1;

            // Count how many consecutive numbers we find.
            int count = 0;

            // IMPORTANT:
            // If (it - 1) does NOT exist, then 'it' is the START
            // of a consecutive sequence.
            //
            // Example:
            // 1, 2, 3, 4
            // 1 is the start because 0 doesn't exist.
            if (st.find(x) == st.end()) {

                // Keep moving forward while the next number exists.
                //
                // Example:
                // x = 0
                // check 1 → exists
                // check 2 → exists
                // check 3 → exists
                // check 4 → exists
                // check 5 → doesn't exist → stop
                while (st.find(x + 1) != st.end()) {

                    // We found another consecutive number.
                    count += 1;

                    // Move x forward by 1.
                    x += 1;
                }

                // Compare this sequence's length with the longest
                // sequence we've found so far.
                longest = max(longest, count);
            }
        }

        // Return the length of the longest consecutive sequence.
        return longest;
    }
};
