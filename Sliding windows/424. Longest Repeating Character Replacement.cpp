class Solution {

public:

    int characterReplacement(string s, int k) {

        // Hashmap:
        // KEY   = character
        // VALUE = how many times that character appears
        //
        // Example:
        // A -> 3
        // B -> 2
        // C -> 1
        unordered_map<char, int> mp;


        // left = starting index of our sliding window
        //
        // Example:
        //        left
        //          ↓
        // s = A A B A C
        //     ↑
        //   window starts here
        int left = 0;


        // Stores the length of the longest VALID window
        // found so far.
        //
        // We don't count how many valid windows we have.
        // We store the BIGGEST window length.
        int max_length = 0;


        // Stores the highest frequency of ONE character
        // inside the current window.
        //
        // Example:
        // Window = A A B A
        //
        // A appears 3 times
        // B appears 1 time
        //
        // max_frq = 3
        int max_frq = 0;


        // 'i' represents the RIGHT side of our sliding window.
        //
        // Every time the loop runs:
        // 1. We add s[i] to the window.
        // 2. We update its frequency.
        // 3. We check whether the window is valid.
        for (int i = 0; i < s.length(); i++) {


            // Add the current character to the hashmap.
            //
            // If s[i] = 'A':
            //
            // Before:
            // A -> 2
            //
            // After:
            // A -> 3
            //
            // ++ means increase the frequency by 1.
            mp[s[i]]++;


            // Check whether the character we JUST added
            // now has the highest frequency.
            //
            // mp[s[i]] gives us the frequency of s[i].
            //
            // Example:
            // max_frq = 2
            // mp['A'] = 3
            //
            // max(2, 3) = 3
            //
            // Therefore:
            // max_frq = 3
            max_frq = max(max_frq, mp[s[i]]);


            // Calculate the current window length.
            //
            // Window goes from:
            // left ---------> i
            //
            // Number of elements between two indices:
            //
            // i - left + 1
            //
            // Example:
            // left = 2
            // i = 5
            //
            // Window:
            // 2, 3, 4, 5
            //
            // Length = 5 - 2 + 1 = 4
            int window_size = i - left + 1;


            // Characters that need to be replaced:
            //
            // window_size - max_frq
            //
            // Why?
            //
            // Suppose:
            //
            // Window = A A A B C
            //
            // window_size = 5
            // max_frq = 3  (A appears 3 times)
            //
            // We keep the A's and replace:
            // B -> A
            // C -> A
            //
            // Replacements needed = 5 - 3 = 2
            //
            // If replacements needed > k,
            // the window is INVALID.
            if (window_size - max_frq > k) {


                // The character at 'left' is leaving
                // the sliding window.
                //
                // So we decrease its frequency.
                //
                // Example:
                //
                // A -> 3
                //
                // s[left] = 'A'
                //
                // After:
                // A -> 2
                mp[s[left]]--;


                // Move the left side of the window one
                // position to the right.
                //
                // This SHRINKS the window.
                //
                // Example:
                //
                // Before:
                // [ A A B A C ]
                //   ↑       ↑
                // left      i
                //
                // After:
                //   [ A B A C ]
                //     ↑
                //    left
                left++;

            }

            else {

                // The window is valid.
                //
                // IMPORTANT:
                // We don't do:
                //
                // max_length++;
                //
                // because max_length is supposed to represent
                // the LONGEST window, not the number of valid windows.
                //
                // So we compare:
                //
                // current window size
                //        vs
                // longest window found so far
                //
                // and keep the bigger one.
                max_length = max(max_length, window_size);
            }
        }


        // Return the length of the longest valid window.
        return max_length;
    }
};
