```cpp
class Solution { 
public: 
    int totalFruit(vector<int>& fruits) { 
        
        // `left` = starting point of our current sliding window.
        // We will move `left` forward whenever the window becomes invalid.
        int left = 0; 
        
        // Map:
        // key   = fruit type
        // value = how many times that fruit appears in the current window
        //
        // Example:
        // fruits = [1, 2, 1]
        // mp = {1: 2, 2: 1}
        //
        // IMPORTANT:
        // mp.size() tells us HOW MANY DIFFERENT fruit types are in the window.
        unordered_map<int, int> mp; 
        
        // Stores the maximum valid window length we have found so far.
        int max_length = 0; 
        
        // `i` is the right side of our sliding window.
        // We expand the window one fruit at a time.
        for (int i = 0; i < fruits.size(); i++) { 
            
            // Add the current fruit to the window.
            //
            // If the fruit already exists:
            //     its frequency increases.
            //
            // If it doesn't exist:
            //     a new key is created with frequency 1.
            mp[fruits[i]]++; 
            
            // We are allowed to have ONLY 2 different fruit types.
            //
            // If there are more than 2:
            //     the current window is INVALID.
            //
            // So we keep shrinking the window from the left
            // until it becomes valid again.
            while (mp.size() > 2) { 
                
                // Remove the fruit at the LEFT side of the window.
                //
                // Example:
                // mp[1] = 3
                // after this:
                // mp[1] = 2
                //
                // We are removing one occurrence, NOT necessarily
                // removing the entire fruit type yet.
                mp[fruits[left]]--; 
                
                // If the frequency becomes 0, it means there are
                // NO MORE of this fruit inside our current window.
                //
                // Therefore, we must remove its key from the map.
                //
                // This is VERY important because:
                // mp.size() = number of DIFFERENT fruit types.
                if (mp[fruits[left]] == 0) { 
                    mp.erase(fruits[left]); 
                } 
                
                // Move the left boundary one position to the right.
                //
                // We already removed fruits[left], so now we advance
                // `left` to represent the smaller window.
                left++; 
            } 
            
            // At this point, the window is guaranteed to be VALID:
            //     mp.size() <= 2
            //
            // Current window:
            //     [left ........ i]
            //
            // Length of this window:
            //     i - left + 1
            //
            // We compare it with the best answer found so far.
            max_length = max(max_length, i - left + 1); 
        } 
        
        // Return the longest contiguous section containing
        // at most 2 different fruit types.
        return max_length; 
    } 
};
```
