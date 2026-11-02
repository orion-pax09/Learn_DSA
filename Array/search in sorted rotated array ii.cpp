class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while (r >= l){
            int middle = l + (r-l)/2;
            if (nums[middle]==target){
                return true;
            }
            if (nums[middle]==nums[l]&&nums[r]==nums[l]&&nums[middle]==nums[r]){
                l +=1;
                r -=1;
                continue;
            }
            if (nums[middle] >= nums[l]){
                if (nums[l] <= target && target < nums[middle]){
                    r = middle - 1;
                }
                else{
                    l = middle + 1;
                }
            }
            else{
                if (nums[middle] < target && target <= nums[r]){
                    l = middle + 1;
                }
                else{
                    r = middle - 1;
                }
            }
        }
        return false;
    }
};
