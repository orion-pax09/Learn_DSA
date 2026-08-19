class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        vector<pair<int,int>>result;
        for (int i = 0 ; i < nums.size() ; i++){
            result.push_back({nums[i] , i});
        }
        sort(result.begin() , result.end());
        while (i < j){
            int sum = result[i].first + result[j].first;
            if (sum > target){
                j--;
            }
            else if (sum < target){
                i++;
            }
            else if (sum == target){
                return {result[i].second , result[j].second};
            }
        }
        return {};
    }
};
