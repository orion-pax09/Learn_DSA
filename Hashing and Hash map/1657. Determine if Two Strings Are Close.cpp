class Solution {
public:
    bool closeStrings(string word1, string word2) {

        // Store each character and its frequency in word1
        unordered_map<char, int> mp;

        // Store each character and its frequency in word2
        unordered_map<char, int> mp1;

        // Store characters that exist in word1
        unordered_set<char> st;

        // Store characters that exist in word2
        unordered_set<char> st1;

        // Store all character frequencies of word1
        // Vector is used because duplicate frequencies matter
        vector<int> frequencyoffirst;

        // Store all character frequencies of word2
        vector<int> frequencyofsecond;


        // Count frequency of every character in word1
        for (int i = 0; i < word1.size(); i++) {
            mp[word1[i]]++;
        }


        // Count frequency of every character in word2
        for (int i = 0; i < word2.size(); i++) {
            mp1[word2[i]]++;
        }


        // Go through word2's hashmap
        for (auto c : mp1) {

            // c.first = character
            // Store every character that exists in word2
            st1.insert(c.first);

            // c.second = frequency
            // Store the frequency in a vector
            frequencyofsecond.push_back(c.second);
        }


        // Go through word1's hashmap
        for (auto c : mp) {

            // Store every character that exists in word1
            st.insert(c.first);

            // Store every character's frequency
            frequencyoffirst.push_back(c.second);
        }


        // Operation 2 allows frequencies to be swapped
        // between characters, so their order doesn't matter.
        //
        // Example:
        // word1 frequencies = [2, 3, 1]
        // word2 frequencies = [1, 2, 3]
        //
        // After sorting:
        // [1, 2, 3]
        // [1, 2, 3]
        sort(
            frequencyoffirst.begin(),
            frequencyoffirst.end()
        );

        sort(
            frequencyofsecond.begin(),
            frequencyofsecond.end()
        );


        // If the frequency distributions are different,
        // the strings cannot be close.
        if (frequencyoffirst != frequencyofsecond) {
            return false;
        }


        // Check that every character in word1
        // also exists in word2.
        for (auto c : mp) {

            // If character is not found in word2's set
            // return false.
            if (st1.find(c.first) == st1.end()) {
                return false;
            }
        }


        // Check that every character in word2
        // also exists in word1.
        for (auto c : mp1) {

            // If character is not found in word1's set
            // return false.
            if (st.find(c.first) == st.end()) {
                return false;
            }
        }


        // Both conditions passed:
        //
        // 1. Same characters exist
        // 2. Same frequency distribution
        //
        // Therefore, the strings are close.
        return true;
    }
};
