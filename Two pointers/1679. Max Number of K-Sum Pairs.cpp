class Solution { 
public: 
    int maxOperations(vector<int>& nums, int k) { 
        
        // Two pointers:
        // left starts at the smallest number
        int left = 0; 
        
        // right starts at the largest number
        int right = nums.size() - 1; 
        
        // This stores how many valid pairs we find
        int answer = 0; 
        
        // Sort the array so two pointers can decide
        // whether to move left or right
        sort(nums.begin(), nums.end()); 
        
        // Keep checking while the two pointers haven't crossed
        while (left < right) { 
            
            // Add the smallest available number
            // and the largest available number
            int sum = nums[left] + nums[right]; 
            
            // If their sum equals k, we found a valid pair
            if (sum == k) { 
                
                // Count this pair
                answer++; 
                
                // Move both pointers because BOTH numbers
                // have now been used in this pair
                left++; 
                right--; 
            } 
            
            // If the sum is too small,
            // we need a BIGGER number
            // so move left forward
            else if (sum < k) { 
                left++; 
            } 
            
            // If the sum is too large,
            // we need a SMALLER number
            // so move right backward
            else { 
                right--; 
            } 
        } 
        
        // Return the total number of valid pairs we found
        return answer; 
    } 
};
