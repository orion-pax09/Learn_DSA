class Solution { 
public: 
    int longestOnes(vector<int>& nums, int k) { 

        // Stores the longest valid window we have found so far
        int max_length = 0; 

        // Left pointer of our sliding window
        int left = 0; 

        // Counts how many 0s are currently inside the window
        int count = 0; 

        // Move the right pointer 'i' through the array
        for (int i = 0 ; i < nums.size() ; i++){ 

            // If the new element is 0, we would need to flip it to 1
            // So increase the number of required flips
            if (nums[i] == 0){ 
                count++; 
            } 

            // If the window needs more than k flips,
            // the window is invalid, so move the left pointer forward
            while(count > k){ 

                // If the element leaving the window is 0,
                // we no longer need to flip that 0
                if (nums[left] == 0){ 
                    count--; 
                } 

                // Remove nums[left] from the window
                // by moving the left pointer one position right
                left++; 
            } 

            // At this point count <= k,
            // so the current window is valid
            if (count <= k){ 

                // Calculate the current window length
                // Window = nums[left ... i]
                // Length = right - left + 1
                int window_size = i - left + 1; 

                // Keep the largest valid window found so far
                max_length = max(max_length , window_size); 
            } 
        } 

        // Return the length of the longest valid window
        return max_length; 
    } 
};
