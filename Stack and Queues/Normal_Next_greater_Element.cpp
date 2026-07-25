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
        vector<int>ans(nums.size() , -1);
        for (int i = ans.size()-1 ; i >= 0 ; i--){
            
            while(!st.empty()&&st.top() <= nums[i]){
                st.pop();
            }
            if (!st.empty()){
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};
int main(){
    //Output: [3, 4, 4, -1]
    vector<int>Arr = {1, 3, 2, 4};
    Solution s;
    vector<int>temp = s.nextGreaterElements(Arr);
    for (auto c : temp){
        cout << c << " ";
    }
}
