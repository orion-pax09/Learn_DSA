class Solution {
public:

    // PLE = Previous Less Element
    // For every element, find the index of the closest smaller element on the left.
    // We store INDEXES in the stack and in the answer array, not the values.
    vector<int> PLE(vector<int>& arr) {

        // Monotonic increasing stack.
        // It stores indexes whose corresponding values are useful candidates
        // for being the Previous Less Element of future elements.
        stack<int> St;

        // Initially, assume there is no smaller element on the left.
        // -1 means "no PLE exists".
        vector<int> ple(arr.size(), -1);

        // Traverse from left to right because PLE is on the LEFT.
        for (int i = 0; i < arr.size(); i++) {

            // Remove elements that are >= current element.
            // They cannot be the Previous Less Element of arr[i].
            //
            // We use >= here so that equal elements are handled by the PLE side.
            // This is important for avoiding duplicate counting in
            // Sum of Subarray Minimums.
            while (!St.empty() && arr[St.top()] >= arr[i]) {
                St.pop();
            }

            // If stack is not empty, the top is the closest smaller element
            // on the left of arr[i].
            if (!St.empty()) {
                ple[i] = St.top();
            }

            // Put current index into the stack.
            // It may become the PLE for a future element.
            St.push(i);
        }

        // Return indexes of Previous Less Elements.
        return ple;
    }


    // NLE = Next Less Element
    // For every element, find the index of the closest smaller OR EQUAL
    // element on the right.
    vector<int> NLE(vector<int>& arr) {

        // Monotonic increasing stack.
        // Again, we store INDEXES, not values.
        stack<int> st;

        // Initially, assume there is no smaller/equal element on the right.
        // -1 means "no NLE exists".
        vector<int> nle(arr.size(), -1);

        // Traverse from right to left because NLE is on the RIGHT.
        for (int i = arr.size() - 1; i >= 0; i--) {

            // Remove elements that are strictly greater than arr[i].
            //
            // We keep equal elements because our PLE already removes
            // equal elements using >=.
            //
            // This asymmetric choice (PLE >= and NLE >) ensures that
            // duplicate minimum values are not counted multiple times.
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If stack is not empty, the top is the closest smaller OR EQUAL
            // element on the right.
            if (!st.empty()) {
                nle[i] = st.top();
            }

            // Put current index into the stack.
            // It may become the NLE for an element to its left.
            st.push(i);
        }

        // Return indexes of Next Less/Equal Elements.
        return nle;
    }


    // Find the sum of minimum values of every possible subarray.
    int sumSubarrayMins(vector<int>& arr) {

        // Find the Previous Less Element index for every position.
        vector<int> nle = NLE(arr);

        // Find the Next Less/Equal Element index for every position.
        vector<int> ple = PLE(arr);

        // LeetCode requires the final answer modulo 1e9 + 7.
        const int mod = 1e9 + 7;

        // Use long long because the sum of contributions can become
        // much larger than the maximum value an int can store.
        long long int total = 0;

        // Calculate the contribution of every element.
        for (int i = 0; i < arr.size(); i++) {

            int right;

            // If NLE is -1, there is no smaller/equal element to the right.
            // Therefore, arr[i] can extend until the END of the array.
            //
            // Example:
            // arr = {3, 1, 2, 4}
            // i = 2
            // right choices = indexes 2 and 3
            // right = arr.size() - i = 4 - 2 = 2
            if (nle[i] == -1) {
                right = arr.size() - i;
            }

            // Otherwise, NLE gives us the boundary where we must stop.
            // Number of possible right endpoints = NLE index - current index.
            else {
                right = nle[i] - i;
            }

            // PLE gives us the boundary on the left.
            //
            // Number of possible left endpoints =
            // current index - PLE index.
            //
            // If PLE is -1:
            // left = i - (-1) = i + 1
            // which correctly counts all possible starting positions.
            int left = i - ple[i];

            // Number of subarrays where arr[i] is the minimum:
            //
            //     left choices × right choices
            //
            // Multiply that by arr[i] to get this element's contribution.
            //
            // 1LL forces the multiplication to happen using long long
            // so that left * right * arr[i] does not overflow int.
            //
            // % mod keeps the value within the required modulo range.
            long long int contribution =
                (1LL * left * right * arr[i]) % mod;

            // Add this element's contribution to the total answer.
            //
            // Apply modulo again to keep total within a safe range
            // and satisfy the problem's modulo requirement.
            total = (total + contribution) % mod;
        }

        // Return the final sum of all subarray minimum contributions.
        return total;
    }
};
