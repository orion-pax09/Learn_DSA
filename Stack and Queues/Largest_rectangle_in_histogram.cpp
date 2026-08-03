class Solution {
public:

    // PLE = Previous Less Element
    // For every bar, find the nearest smaller bar on the LEFT.
    // We store the INDEX of that smaller bar.
    vector<int> PLE(vector<int>& arr) {

        // Stack stores INDICES of bars.
        // We maintain a monotonic increasing stack.
        stack<int> st;

        // Initially, assume there is no smaller element.
        // -1 means "no smaller element found".
        vector<int> ans(arr.size(), -1);

        // Traverse from LEFT to RIGHT.
        for (int i = 0; i < arr.size(); i++) {

            // Remove bars that are GREATER than the current bar.
            // They cannot be the PLE of the current bar.
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If stack is not empty, the top is the nearest
            // smaller element on the left.
            if (!st.empty()) {
                ans[i] = st.top();
            }

            // Push current index so it can help future elements.
            st.push(i);
        }

        // Return the index of PLE for every element.
        return ans;
    }


    // NLE = Next Less Element
    // For every bar, find the nearest smaller bar on the RIGHT.
    // We store the INDEX of that smaller bar.
    vector<int> NLE(vector<int>& arr) {

        // Stack stores INDICES of bars.
        // We maintain a monotonic increasing stack.
        stack<int> st;

        // Initially, assume there is no smaller element.
        // -1 means "no smaller element found".
        vector<int> ans(arr.size(), -1);

        // Traverse from RIGHT to LEFT.
        for (int i = arr.size() - 1; i >= 0; i--) {

            // Remove bars that are GREATER THAN OR EQUAL TO
            // the current bar.
            // They cannot be the NLE of the current bar.
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // If stack is not empty, the top is the nearest
            // smaller element on the right.
            if (!st.empty()) {
                ans[i] = st.top();
            }

            // Push current index so it can help future elements.
            st.push(i);
        }

        // Return the index of NLE for every element.
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {

        // Find the index of the Next Less Element for every bar.
        vector<int> nle = NLE(heights);

        // Find the index of the Previous Less Element for every bar.
        vector<int> ple = PLE(heights);

        // Store the largest rectangle area found so far.
        int MAX = INT_MIN;

        // Treat EVERY bar as the minimum height of a rectangle.
        for (int i = 0; i < heights.size(); i++) {

            // If there is no NLE, the rectangle can extend
            // all the way to the END of the array.
            // So use heights.size() as the right boundary.
            int right = (nle[i] == -1) ? heights.size() : nle[i];

            // If there is no PLE, the rectangle can extend
            // all the way to the START of the array.
            // We use -1 as the imaginary boundary before index 0.
            int left = (ple[i] == -1) ? -1 : ple[i];

            // PLE and NLE themselves cannot be included
            // because they are SMALLER than the current height.
            //
            // Example:
            // PLE = 1, NLE = 4
            // Width = 4 - 1 - 1 = 2
            //
            // The rectangle covers indices 2 and 3.
            int width = right - left - 1;

            // Current bar's height × the number of bars
            // it can cover = rectangle area.
            int H = heights[i] * width;

            // Keep the largest area found so far.
            MAX = max(MAX, H);
        }

        // Return the largest rectangle area.
        return MAX;
    }
};
