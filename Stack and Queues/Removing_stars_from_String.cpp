#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        stack<string>st;
        string ans ="";
        for (int i = 0 ; i < s.size() ; i++){
            if (s[i]!='*'){
                string temp(1,s[i]);
                st.push(temp);
            }
            else{
                st.pop();
            }
        }
                while(!st.empty()){
                ans +=st.top();
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};
int main(){
    Solution s;
    cout << s.removeStars("leet**cod*e");
}
