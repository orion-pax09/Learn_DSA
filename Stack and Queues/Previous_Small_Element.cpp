#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> Previous_Smaller_Element(vector<int>& nums) {
        stack<int>st;
        vector<int>ans(nums.size());
        for (int i = 0 ; i < nums.size() ; i++){
            while(!st.empty()&&st.top() >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                st.push(ans[i]);
            }
        }
        return ans;
    }
};

int main(){
Solution s;
vector<int>arr = {5,7,9,6,7,4,5,1,3,7};
/*
-1 5 7 5 6 -1 4 -1 1 3 
*/
vector<int>ARR = s.nextGreaterElement(arr);
for (auto c : ARR){
    cout << c<< " ";
}
}
