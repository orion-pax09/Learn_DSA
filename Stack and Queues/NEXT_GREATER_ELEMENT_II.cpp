#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>ans(nums.size());
        int n = nums.size();
        for (int i = 2* ans.size()-1 ; i >= 0 ; i--){
        
            while (!st.empty()&&nums[i%n] >= st.top())
            {
                st.pop();
            }
            if (n > i){
                if(st.empty()){
                    ans[i] = -1;
                }
                else{
                ans[i] = st.top();

                }
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};
int main(){
    //Output: [2,-1,2]
    vector<int>Arr = {1,2,1};
    Solution s;
    vector<int>temp = s.nextGreaterElements(Arr);
    for (auto c : temp){
        cout << c << " ";
    }
}
