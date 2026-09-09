class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // If the string is empty, there is no substring.
        // So the longest length is 0.
        if (s.length() == 0) {
            return 0;
        }

        // Store the total number of characters in the string.
        int n = s.length();

        // right = end of our sliding window.
        // It moves forward to EXPAND the window.
        int right = 0;

        // left = beginning of our sliding window.
        // It moves forward to SHRINK the window when we find a duplicate.
        int left = 0;

        // This set stores the characters currently inside our window.
        //
        // Example:
        // s = "abc"
        // window = "abc"
        // seen = {'a', 'b', 'c'}
        //
        // The purpose of the set is to quickly check:
        // "Have I already seen this character inside my current window?"
        unordered_set<char> seen;

        // Length of the current valid window.
        int distance = 0;

        // Stores the largest valid window we have found.
        int max_size = INT_MIN;


        // Keep expanding/shrinking the window
        // until right reaches the end of the string.
        while (right < n) {

            // Check whether s[right] is NOT already
            // inside our current window.
            if (seen.find(s[right]) == seen.end()) {

                // No duplicate!
                // Add the new character to our window.
                seen.insert(s[right]);

                // Move right forward because we successfully
                // added s[right] to the window.
                right++;

                // Calculate the current window length.
                //
                // right is one position AFTER the window,
                // while left points to the beginning.
                //
                // Example:
                // left = 0
                // right = 3
                // window = "abc"
                // length = 3 - 0 = 3
                distance = right - left;

                // Compare the current window with the best
                // window found so far.
                //
                // We keep the larger one.
                max_size = max(max_size, distance);
            }

            else {

                // Duplicate found!
                //
                // We cannot keep the current window because
                // it contains the same character twice.
                //
                // So remove the character at the LEFT side
                // of the window.
                seen.erase(s[left]);

                // Move left forward to shrink the window.
                //
                // We keep shrinking until the duplicate
                // is removed from the window.
                left++;
            }
        }

        // Return the largest substring length we found.
        return max_size;
    }
};
