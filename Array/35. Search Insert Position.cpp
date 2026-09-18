class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while (low <=high){
            int middle = (low+high)/2;
            if (nums[middle] == target){
                return middle;
            }
            else if (nums[middle] < target){
                low = middle + 1;
            }
            else{
                high = middle - 1;
            }
        }
        return low;
    }
};
