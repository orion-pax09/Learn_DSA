#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include <queue>
using namespace std;
class Solution {
public:
int priority(char c){
    if (c == '^'){
        return 3;
    }
    else if (c=='*' || c=='/' || c=='%'){
        return 2;
    }
    else if (c=='+'||c=='-'){
        return 1;
    }
    return 0;
}
string infixToPostfix(string s) {
    stack<char> st;
    int i = 0;
    int n = s.size();
    string ans="";
    while(i < n){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i] <='z')||(s[i]>='0' && s[i] <='9')){
            ans = ans + s[i];
        }

        else if (s[i]=='('){
            st.push(s[i]);
        }
        else if (s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                ans +=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty()&&priority(st.top())>=priority(s[i])){
                ans +=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}
};

int main(){
    
    /*
    abc+*d/
    */
    string temp = "a*(b+c)/d";

   Solution s;
   cout<<s.infixToPostfix(temp);

    

}
