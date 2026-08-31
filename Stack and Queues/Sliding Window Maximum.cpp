class Solution { 
public: 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { 
        
        // Deque stores INDEXES of useful elements.
        // Values in the deque are kept in DECREASING order.
        // Front always points to the maximum value's index.
        deque<int> q; 
        
        // Stores the maximum value from every window.
        vector<int> ans; 
        
        // Move through every element using i as the RIGHT pointer.
        for (int i = 0; i < nums.size(); i++) { 
            
            // Remove indexes from the FRONT that are outside
            // the current window of size k.
            //
            // Current window starts at: i - k + 1
            // Anything <= i - k is outside the window.
            while (!q.empty() && q.front() <= i - k) { 
                q.pop_front(); 
            } 
            
            // Remove indexes from the BACK if their values are
            // smaller than or equal to the current value.
            //
            // Why? nums[i] is newer and greater, so those smaller
            // values can never become the maximum before nums[i]
            // leaves the window.
            while (!q.empty() && nums[q.back()] <= nums[i]) { 
                q.pop_back(); 
            } 
            
            // Add the current index to the BACK of the deque.
            q.push_back(i); 
            
            // The first complete window of size k ends at index k - 1.
            // Once i >= k - 1, we have a complete window.
            if (i >= k - 1) { 
                
                // The FRONT of the deque contains the index
                // of the maximum value in the current window.
                ans.push_back(nums[q.front()]); 
            } 
        } 
        
        // Return the maximum value from every sliding window.
        return ans; 
    } 
};
