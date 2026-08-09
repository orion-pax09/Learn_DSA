class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Hashmap:
        // key   = number
        // value = frequency of that number
        unordered_map<int, int> mp;

        // This vector will store:
        // {number, frequency}
        vector<pair<int, int>> ans;

        // Go through every number in nums
        for (int i = 0; i < nums.size(); i++) {

            // Increase the frequency of nums[i]
            // Example: if nums[i] = 2,
            // mp[2] gets increased by 1
            mp[nums[i]]++;
        }

        // Go through every key-value pair in the hashmap
        for (auto c : mp) {

            // c.first  = number
            // c.second = frequency
            //
            // Store {number, frequency} inside the vector
            ans.push_back({c.first, c.second});
        }

        // Sort the vector based on FREQUENCY
        // We want the highest frequency FIRST
        sort(ans.begin(), ans.end(), [](auto &a, auto &b) {

            // a.second = frequency of pair a
            // b.second = frequency of pair b
            //
            // > means larger frequency comes first
            return a.second > b.second;
        });

        // This will store our final answer
        vector<int> result;

        // We only need the first k elements
        // because sorting put the highest frequencies first
        for (int i = 0; i < k; i++) {

            // ans[i].first = the actual number
            // Add that number to our answer
            result.push_back(ans[i].first);
        }

        // Return the k most frequent numbers
        return result;
    }
};
