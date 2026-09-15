```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        // 'left' represents the LEFT boundary of our sliding window.
        // We move it forward whenever our window becomes invalid.
        int left = 0;

        // 'count' keeps track of how many 0s are currently inside
        // our sliding window.
        //
        // Why do we count 0s?
        // Because we are allowed to DELETE exactly one element.
        // Therefore, our window can contain AT MOST one 0.
        int count = 0;

        // Stores the maximum valid answer found so far.
        // We can initialize it to 0 because the answer is never negative.
        int max_length = 0;

        // 'i' is the RIGHT boundary of our sliding window.
        // We expand the window one element at a time.
        for (int i = 0; i < nums.size(); i++) {

            // If the newly added element is 0,
            // increase the number of zeros inside the window.
            if (nums[i] == 0) {
                count++;
            }

            // Our window is INVALID if it contains more than one 0.
            //
            // Example:
            // [1 1 0 1 0]
            //         ↑
            //      2 zeros
            //
            // We cannot delete both zeros because we can delete
            // only ONE element.
            while (count > 1) {

                // We are removing nums[left] from the window.
                //
                // If the element being removed is 0,
                // decrease our zero counter.
                if (nums[left] == 0) {
                    count--;
                }

                // Move the LEFT boundary one position to the right.
                // This shrinks the window until it contains at most
                // one zero again.
                left++;
            }

            // At this point, the window is VALID:
            // it contains either 0 or 1 zero.
            //
            // Current window:
            // [left ........ i]
            //
            // Window size = right - left + 1
            int window_size = i - left + 1;

            // We MUST delete exactly one element.
            //
            // If the window contains one 0:
            //
            // [1 1 0 1]
            //       ↑
            //     delete
            //
            // 4 elements -> delete 1 -> 3 ones
            //
            // If the window contains no 0:
            //
            // [1 1 1 1]
            //
            // We STILL have to delete one element.
            // 4 elements -> delete 1 -> 3 ones
            //
            // Therefore, the answer for this window is always:
            // window_size - 1
            max_length = max(max_length, window_size - 1);
        }

        // Return the largest number of consecutive 1s
        // we can have after deleting exactly one element.
        return max_length;
    }
};
```
