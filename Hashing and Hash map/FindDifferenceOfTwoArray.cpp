class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1;
        unordered_set<int>s2;
        for (int i = 0 ; i < nums1.size() ; i++){
            s1.insert(nums1[i]);
        }
        for (int i = 0 ; i < nums2.size() ; i++){
            s2.insert(nums2[i]);
        }
        vector<int>r1;
        for (auto x : s1){
            if (s2.find(x)==s2.end()){
                r1.push_back(x);
            }
        }
        vector<int>r2;
        for (auto x:s2){
            if (s1.find(x)==s1.end()){
                r2.push_back(x);
            }
        }
        vector<vector<int>>result({r1 , r2});
        return result;
    }
};
