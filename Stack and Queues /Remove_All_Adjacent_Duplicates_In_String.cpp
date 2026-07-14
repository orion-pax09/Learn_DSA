class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>currentchar;
        int o = 0 ;
        while (o < s.length()){
            if (!currentchar.empty()&&currentchar.top()==s[o]){
                currentchar.pop();
            }
            else{
                currentchar.push(s[o]);
            }
            o++;
        }

        string new_st;
        while (!currentchar.empty()){
            new_st+=currentchar.top();
            currentchar.pop();
        }
        reverse(new_st.begin() , new_st.end());
        return new_st;
    }
};
