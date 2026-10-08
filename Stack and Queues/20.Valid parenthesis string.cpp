class Solution {
public:
    bool checkValidString(string s) {
        int maximum = 0;
        int minimum = 0;
        for (int i = 0 ; i < s.size() ; i++){
            if (s[i]=='('){
                maximum++;
                minimum++;
            }
            else if (s[i]==')'){
                maximum--;
                minimum = max(0 , minimum-1);
            }
            else{
                maximum++;
                minimum = max(0 , minimum-1);
            }
            if (maximum < 0){
                return false;
            }
        }
        return minimum==0;
    }
};
