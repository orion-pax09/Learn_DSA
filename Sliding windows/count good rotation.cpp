class Solution {
public:
    int countGoodRotations(vector<int>& nums) {

        // Store the total sum of all elements in the array
        long long int total_sum = 0;

        // Count how many rotations are "good"
        int score = 0;

        // Calculate the total sum
        for (auto x : nums){
            total_sum += x;
        }

        // 'window' stores the sum of the first half of the array
        long long int window = 0;

        // We divide the array into two equal halves
        int half = nums.size() / 2;

        // Calculate the sum of the first half
        for (int i = 0; i < half; i++){
            window += nums[i];
        }

        // Try every possible rotation
        for (int rotation = 0; rotation < nums.size(); rotation++){

            // The other half's sum = total sum - first half's sum
            long long int second = total_sum - window;

            // If the second half is larger, this rotation is good
            if (second > window){
                score++;
            }

            // Remove the element leaving the sliding window
            window -= nums[rotation];

            // Add the new element entering the window
            // '%' makes the index wrap around to the beginning
            window += nums[(rotation + half) % nums.size()];
        }

        // Return the number of good rotations
        return score;
    }
};
