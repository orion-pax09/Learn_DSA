class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // Store the sum of the current window.
        double sum = 0;

        // Build the FIRST window containing exactly k elements.
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        // The first window is initially our maximum-sum window.
        double max_avg = sum;

        // Start from index k and SLIDE the window to the right.
        for (int i = k; i < nums.size(); i++) {

            // Remove the element that is leaving the window.
            // i - k points to the leftmost element of the old window.
            sum -= nums[i - k];

            // Add the new element entering the window from the right.
            sum += nums[i];

            // Save the largest window sum seen so far.
            max_avg = max(sum, max_avg);
        }

        // Convert the maximum sum into the maximum average.
        return max_avg / k;
    }
};
