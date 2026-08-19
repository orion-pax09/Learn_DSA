class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int anchor = 0;
        for (int explorer = 0 ; explorer < nums.size() ; explorer++){
            if (nums[explorer]!=0){
                int temp = nums[anchor];
                nums[anchor] = nums[explorer];
                nums[explorer] = temp;
                anchor++;
            }
        }
        for (int i = 0 ; i<nums.size() ; i++){
            cout << nums[i];
        }
    }
};
