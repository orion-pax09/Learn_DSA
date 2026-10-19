class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>QS;
        int x=0;
        vector<int>vt;
        for (int i = 0 ; i < nums.size() ; i++){
            QS.push(nums[i]);
        }
        int ans;
        while (x < k){
            ans = QS.top();
            QS.pop();
            x++;
        }
        return ans; 
    }
};
