```cpp
class Solution {
public:

    // 3Sum: find all unique triplets whose three values add up to 0
    vector<vector<int>> threeSum(vector<int>& nums) {

        // This will store every valid triplet we find
        vector<vector<int>> res;

        // Save the size of the array so we know the valid index range
        int n = nums.size();

        // Sort first!
        // Sorting is what allows us to use the two-pointer technique:
        // j can move right to get a bigger value, and k can move left to get a smaller value
        sort(nums.begin(), nums.end());

        // i chooses the first number of our triplet
        // For every nums[i], j and k will search for the other two numbers
        for (int i = 0; i < n; i++) {

            // If the current value is the same as the previous value,
            // skip it because we already searched for this first number.
            // This prevents duplicate triplets.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // j starts just after i and searches from the left
            int j = i + 1;

            // k starts at the last index and searches from the right
            int k = n - 1;

            // Keep searching while j and k have not crossed each other
            // We need two different positions for the remaining two numbers
            while (j < k) {

                // Check the sum of the three numbers currently selected by i, j and k
                int sum = nums[i] + nums[j] + nums[k];

                // Sum is too small (< 0)
                // Because the array is sorted, move j right to get a larger number
                if (sum < 0) {
                    j++;
                }

                // Sum is too large (> 0)
                // Because the array is sorted, move k left to get a smaller number
                else if (sum > 0) {
                    k--;
                }

                // If the sum is neither too small nor too large,
                // it must be exactly 0 -> we found a valid triplet
                else {

                    // Save the current triplet because its sum is 0
                    res.push_back({nums[i], nums[j], nums[k]});

                    // Move both pointers inward to search for another triplet
                    // We already used the current j and k values
                    j++;
                    k--;

                    // Skip duplicate values on the left
                    // Otherwise we could add the same triplet more than once
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    // Skip duplicate values on the right
                    // Same reason: avoid duplicate triplets
                    while (k > j && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }

        // Return all unique triplets we found
        return res;
    }
};
```
