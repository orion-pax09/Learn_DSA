class Solution {
public:

    // Function that sorts the array according to frequency
    vector<int> frequencySort(vector<int>& nums) {

        // HashMap:
        // key   = number
        // value = frequency of that number
        unordered_map<int,int> mp;

        // This will store:
        // {number, frequency}
        vector<pair<int,int>> ans;


        // Go through every number in nums
        for (int i = 0; i < nums.size(); i++) {

            // Increase the frequency of nums[i]
            // Example: if nums[i] = 2
            // mp[2]++ means increase frequency of 2 by 1
            mp[nums[i]]++;
        }


        // Go through every key-value pair in the HashMap
        for (auto c : mp) {

            // c.first  = number
            // c.second = frequency
            //
            // Store them together as:
            // {number, frequency}
            ans.push_back({c.first, c.second});
        }


        // Sort the pairs using our custom sorting rule
        sort(ans.begin(), ans.end(), [](auto& a, auto& b) {

            // First priority:
            // Sort by frequency in INCREASING order
            //
            // Example:
            // frequency 1 comes before frequency 2
            if (a.second != b.second) {
                return a.second < b.second;
            }

            // If two numbers have the SAME frequency,
            // use the second rule:
            //
            // Sort the numbers themselves in DECREASING order
            //
            // Example:
            // 5 and 2 both appear 3 times
            // 5 should come before 2
            else {
                return a.first > b.first;
            }
        });


        // This will contain our final sorted array
        vector<int> result;


        // Go through every {number, frequency} pair
        for (int i = 0; i < ans.size(); i++) {

            // Counter used to repeat the number
            // according to its frequency
            int limit = 0;


            // Repeat ans[i].first exactly ans[i].second times
            //
            // Example:
            // ans[i] = {3, 2}
            //
            // 3 should appear 2 times:
            // 3 3
            while (limit < ans[i].second) {

                // Add the number to the result
                result.push_back(ans[i].first);

                // Increase counter
                limit++;
            }
        }


        // Return the final sorted array
        return result;
    }
};
