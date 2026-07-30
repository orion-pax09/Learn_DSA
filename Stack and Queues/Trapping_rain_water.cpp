#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int Trapping_rainm_water(vector<int>& height) {

        // Stack stores INDICES, not actual heights.
        // We use these indices to find:
        // 1. Bottom of the valley
        // 2. Left boundary
        // 3. Width between left and right boundaries
        stack<int> st;

        int total = 0;

        for (int i = 0; i < height.size(); i++) {

            // Current index 'i' acts as the RIGHT boundary.
            // If current height is greater than the stack top,
            // we found a valley that can trap water.
            while (!st.empty() && height[i] > height[st.top()]) {

                // The top of the stack is the BOTTOM of the valley.
                // It is the smaller bar between the left and right boundaries.
                int bottom = st.top();
                st.pop();

                // After removing the bottom:
                // The new stack top becomes the LEFT boundary.
                //
                // Current index 'i' is the RIGHT boundary.
                //
                // So we now have:
                //
                //        LEFT       RIGHT
                //          |           |
                //          |  BOTTOM   |
                //          |     |     |
                //          L     B     R
                //
                // If stack is empty, there is no LEFT boundary,
                // so no water can be trapped.
                if (!st.empty()) {

                    int left = st.top();
                    int right = i;

                    // Water height is limited by the SHORTER boundary.
                    // Then subtract the height of the bottom.
                    int waterHeight =
                        min(height[left], height[right])
                        - height[bottom];

                    // Width = number of positions BETWEEN left and right.
                    // That's why we subtract 1.
                    int width = right - left - 1;

                    // Water trapped in this valley
                    // = water height × width
                    total += waterHeight * width;
                }
            }

            // Push current index into the stack.
            // We store the index because we need it later
            // to calculate both height and width.
            st.push(i);
        }

        return total;
    }
};

int main() {

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution s;

    cout << s.Trapping_rainm_water(height);
}
