#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for (auto a : asteroids){
            while(!st.empty()&&a<0&&st.top()>0){
                if(abs(a) > st.top()){
                    st.pop();
                }
                else if (abs(a)==st.top()){
                    st.pop();
                    a=0;
                    break;
                }
                else{
                    a = 0;
                    break;
                }
            }
            if(a!=0){
                st.push(a);
            }
        }
        vector<int>result;
        while(!st.empty()){
            if (st.top()!=0){
            result.push_back(st.top());
            st.pop();
            }
            else{
                st.pop();
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
int main(){
    vector<int>array = {-2,2,-1,-2};
    Solution s;
    vector<int>S = s.asteroidCollision(array);
    for (int i = 0 ; i < S.size() ; i++){
        cout << S[i]<<" ";
    }
}
