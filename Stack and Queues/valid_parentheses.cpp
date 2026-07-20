class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (int i = 0 ; i < s.size() ; i++){
            if (s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if (st.empty()){
                    return false;
                }

                char curr = st.top();
                if ((curr == '(' && s[i]==')')||(curr == '{' && s[i]=='}')||(curr == '[' && s[i]==']')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();

    }
};
