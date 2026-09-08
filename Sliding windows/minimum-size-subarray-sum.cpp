class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int right = 0;       // RIGHT expands the window → moves forward
        int left = 0;        // LEFT shrinks the window → moves forward
        int sum = 0;         // Sum of the CURRENT window only

        int min_window = INT_MAX; // Best/smallest valid window length found so far

        while (right < nums.size()) {

            // If sum is too small, window is invalid → EXPAND from the right
            if (sum < target) {
                sum += nums[right]; // Add the new element entering the window
                right++;             // Move right forward
            }

            // If sum >= target, window is VALID → try to make it smaller
            while (sum >= target) {

                // Current window length:
                // right is one position AFTER the last element
                int size = right - left;

                // Save the smallest valid window length we've seen
                min_window = min(size, min_window);

                // Remove the leftmost element to SHRINK the window
                sum -= nums[left];

                // Move left forward because that element left the window
                left++;
            }
        }

        // INT_MAX means we NEVER found a window with sum >= target
        if (min_window == INT_MAX) {
            return 0;
        }

        // Return the smallest valid window length
        return min_window;
    }
};
