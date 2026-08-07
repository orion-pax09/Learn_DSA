class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char,int> mp;   
        // stores each character of s as key and its frequency as value

        unordered_map<char,int> mp1;  
        // stores each character of t as key and its frequency as value

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            // increase the frequency of the current character
        }

        for (int i = 0; i < t.size(); i++) {
            mp1[t[i]]++;
            // increase the frequency of the current character
        }

        if (mp == mp1) {
            // map comparison checks key-value pairs, so frequencies are compared too
            return true;
        }

        return false;
    }
};
