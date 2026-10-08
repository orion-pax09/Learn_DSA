#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int precedence(char op){
    if (op=='+'||op=='-'){
        return 1;
    }
    else if (op=='*'||op=='/'){
        return 2;
    }
    else if (op=='^'){
        return 3;
    }
    return 0;
}
void to_postfix(string s){
    string res = "";
    int i =0;
    stack<char>st;
    int size = s.size();
    while (i < size){
        if ((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
            res = res + s[i];
        }
        else if (s[i]=='('){
            st.push(s[i]);
        }
        else if (s[i]==')'){
            while (!st.empty()&&st.top()!='('){
                res = res + st.top();
                st.pop();
            }
            if (!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty()&&st.top()!='('&&precedence(st.top())>=precedence(s[i])){
                res = res + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    cout << res;
}
int main(){
    string s = "(A+B*C)/(D-(E-F))";
    to_postfix(s);
}
