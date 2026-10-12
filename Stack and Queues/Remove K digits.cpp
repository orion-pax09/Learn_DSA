class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;   // Stores digits in increasing order when possible
        string res = "";  // Stores the final answer
        int n = num.size(); // Total number of digits in the input

        // Process each digit from left to right
        for (int i = 0; i < n; i++) {

            // If the stack's top digit is greater than the current digit,
            // remove it to make the resulting number smaller.
            // k > 0 ensures we never remove more digits than allowed.
            while (!st.empty() && st.top() > num[i] && k > 0) {

                st.pop(); // Remove the larger digit from the stack
                k--;      // One removal has been used
            }

            // Keep the current digit after removing any larger digits
            st.push(num[i]);
        }

        // If removals are still needed after processing all digits,
        // remove digits from the right (the end of the number).
        while (k > 0 && !st.empty()) {

            st.pop(); // Remove the last remaining digit
            k--;      // Decrease the number of removals left
        }

        vector<char> temp; // Temporarily stores digits popped from the stack

        // A stack follows LIFO (Last In, First Out),
        // so popping its digits gives them in reverse order.
        while (!st.empty()) {

            temp.push_back(st.top()); // Copy the top digit into the vector
            st.pop();                 // Remove it from the stack
        }

        // Because temp is reversed, leading zeros in the original number
        // appear at the BACK of temp. Remove those zeros first.
        while (!temp.empty() && temp.back() == '0') {

            temp.pop_back(); // Remove a leading zero from the original number
        }

        // Restore the digits to their original left-to-right order
        reverse(temp.begin(), temp.end());

        // Build the final result string from the vector
        for (int i = 0; i < temp.size(); i++) {

            res += temp[i]; // Append each digit to the answer
        }

        // If all digits were removed or only zeros remained, return "0"
        return res.empty() ? "0" : res;
    }
};
