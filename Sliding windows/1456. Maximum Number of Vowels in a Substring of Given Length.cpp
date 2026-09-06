class Solution {

public:

    // Function to check whether a character is a vowel
    bool is_valid(char s) {

        // Check if the character is any uppercase or lowercase vowel
        if (s == 'a' || s == 'A' ||
            s == 'E' || s == 'e' ||
            s == 'I' || s == 'i' ||
            s == 'o' || s == 'O' ||
            s == 'U' || s == 'u') {

            // Return true if s is a vowel
            return true;
        }

        // Return false if s is not a vowel
        return false;
    }


    // Main function: find the maximum number of vowels
    // in any substring of length k
    int maxVowels(string s, int k) {

        // 'sum' stores the number of vowels
        // in the current sliding window
        int sum = 0;


        // Create the first window of size k
        // Example: k = 3 → s[0], s[1], s[2]
        for (int i = 0; i < k; i++) {

            // Check whether the current character is a vowel
            if (is_valid(s[i])) {

                // If it is a vowel, increase the vowel count
                sum++;
            }
        }


        // The first window's vowel count is initially
        // our maximum number of vowels
        int max_vowels = sum;


        // Start sliding the window
        // i starts from k because the first window is already processed
        for (int i = k; i < s.length(); i++) {

            // s[i-k] is the character leaving the window
            if (is_valid(s[i-k])) {

                // If the leaving character was a vowel,
                // remove it from our current count
                sum--;
            }


            // s[i] is the new character entering the window
            if (is_valid(s[i])) {

                // If the entering character is a vowel,
                // add it to our current count
                sum++;
            }


            // Compare the current window's vowel count
            // with the maximum found so far
            max_vowels = max(sum, max_vowels);
        }


        // Return the maximum number of vowels found
        return max_vowels;
    }
};
