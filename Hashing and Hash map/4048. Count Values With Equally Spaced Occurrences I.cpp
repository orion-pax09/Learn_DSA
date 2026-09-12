class Solution { 
public: 

    // Function takes the nums array and returns
    // the number of special integers.
    int countSpecialIntegers(vector<int>& nums) { 
        
        // Stores how many different integers are special.
        int count = 0; 
        
        // Create an unordered_map where:
        //
        // KEY   = the number from nums
        // VALUE = vector containing all indices where that number appears
        //
        // Example:
        // nums = [1, 8, 1, 5, 1]
        //
        // map will become:
        // 1 -> [0, 2, 4]
        // 8 -> [1]
        // 5 -> [3]
        unordered_map<int, vector<int>> map; 
        
        
        // Go through every element of nums.
        //
        // i represents the CURRENT INDEX.
        //
        // Example:
        // nums = [1, 8, 1]
        //
        // i = 0 -> nums[i] = 1
        // i = 1 -> nums[i] = 8
        // i = 2 -> nums[i] = 1
        for (int i = 0; i < nums.size(); i++) { 
            
            // Find the vector belonging to nums[i]
            // and add the current index i to that vector.
            //
            // Example:
            // i = 0, nums[i] = 1
            // map[1].push_back(0)
            //
            // map:
            // 1 -> [0]
            //
            // Later i = 2:
            // map[1].push_back(2)
            //
            // map:
            // 1 -> [0, 2]
            map[nums[i]].push_back(i); 
        } 
        
        
        // Now the map is completely built.
        //
        // Go through EVERY key-value pair in the map.
        //
        // value = the actual number
        // pos   = vector containing all indices of that number
        //
        // Example:
        // value = 1
        // pos = [0, 2, 4]
        //
        // Then another iteration might be:
        // value = 8
        // pos = [1, 6]
        for (auto& [value, pos] : map) { 
            
            // A number is special ONLY if it appears
            // EXACTLY 3 times.
            //
            // pos.size() tells us how many times
            // this number appeared.
            //
            // Example:
            // pos = [0, 2, 4]
            // pos.size() = 3 -> possible special
            //
            // pos = [1, 6]
            // pos.size() = 2 -> NOT special
            //
            // pos = [0, 1, 2, 3]
            // pos.size() = 4 -> NOT special
            if (pos.size() == 3) { 
                
                // We now know that this number appears
                // exactly 3 times.
                //
                // pos[0] = first occurrence index
                // pos[1] = second occurrence index
                // pos[2] = third occurrence index
                //
                // We check whether the distance from
                // first -> second is equal to
                // second -> third.
                //
                // Example:
                //
                // pos = [0, 2, 4]
                //
                // 2 - 0 = 2
                // 4 - 2 = 2
                //
                // 2 == 2 -> equally spaced -> SPECIAL
                if (pos[1] - pos[0] == pos[2] - pos[1]) { 
                    
                    // We found ONE special integer.
                    //
                    // Increase the answer by 1.
                    count++; 
                } 
            } 
        } 
        
        // Return the total number of special integers.
        return count; 
    } 
};
