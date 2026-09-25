class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // If there are NO strings, there is no common prefix.
        if (strs.size() == 0) {
            return "";
        }

        // This stores the common characters we find.
        // Example: "" → "f" → "fl"
        string result = "";

        // i = CHARACTER POSITION we are currently checking.
        // We use strs[0] (the first string) as our reference.
        //
        // Example:
        // strs[0] = "flower"
        // index:    0 1 2 3 4 5
        //           f l o w e r
        //
        // So i moves: 0 → 1 → 2 → 3 → ...
        for (int i = 0; i < strs[0].size(); i++) {

            // Take the character at position i from the FIRST string.
            // This is the character that every other string
            // must match.
            //
            // Example:
            // i = 0 → current = 'f'
            // i = 1 → current = 'l'
            // i = 2 → current = 'o'
            char current = strs[0][i];

            // j = WHICH STRING we are checking.
            //
            // Start at 1 because strs[0] is our reference string.
            //
            // Example:
            // j = 1 → compare with "flow"
            // j = 2 → compare with "flight"
            for (int j = 1; j < strs.size(); j++) {

                // STOP if EITHER:
                //
                // 1. i >= strs[j].size()
                //    → This string is too short.
                //    → It doesn't have a character at position i.
                //
                // OR
                //
                // 2. strs[j][i] != current
                //    → The character doesn't match the first string.
                //
                // Example:
                //
                // flower → f l o
                // flow   → f l o
                // flight → f l i
                //               ↑
                //          mismatch!
                //
                // Once ANY string fails, the common prefix is finished.
                if (i >= strs[j].size() || strs[j][i] != current) {

                    // Return everything that matched BEFORE this point.
                    //
                    // Example:
                    // result = "fl"
                    // current comparison fails
                    // → return "fl"
                    return result;
                }
            }

            // If we reached here, EVERY string had the same
            // character at position i.
            //
            // So add that character to our answer.
            //
            // Example:
            // current = 'f' → result = "f"
            // current = 'l' → result = "fl"
            // current = 'o' → result = "flo"
            result += current;
        }

        // If the loop finishes, the entire first string
        // was a common prefix.
        return result;
    }
};
