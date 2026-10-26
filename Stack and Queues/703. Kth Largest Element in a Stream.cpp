class KthLargest {
public:
    int k;
    KthLargest*arr;
    priority_queue<int , vector<int> , greater<int>>PQ;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0 ; i < nums.size() ; i++){
            PQ.push(nums[i]);
        }
    }
    
    int add(int val) {
        PQ.push(val);
        while (PQ.size() > k){
            PQ.pop();
        }
        return PQ.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
