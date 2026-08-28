```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {

        // Two pointers start at the farthest positions.
        // This gives us the maximum possible width initially.
        int left = 0;
        int right = height.size() - 1;

        // Stores the maximum amount of water found so far.
        int maxwater = 0;

        // Continue until both pointers meet.
        // We need two different lines to form a container.
        while (left < right) {

            // Distance between the two selected vertical lines.
            int width = right - left;

            // Water can only reach the height of the SHORTER wall.
            // Otherwise, water would spill over that shorter wall.
            int min_height = min(height[left], height[right]);

            // Area = width × height of the shorter wall.
            int area = min_height * width;

            // Keep the maximum area found so far.
            maxwater = max(maxwater, area);

            // Move the SHORTER wall because it is limiting the water height.
            // Moving the taller wall only decreases the width while the
            // shorter wall remains the bottleneck.
            if (height[right] >= height[left]) {

                // Left wall is shorter (or equal), so move it and
                // hope to find a taller wall that can hold more water.
                left++;
            }
            else {

                // Right wall is shorter, so move it and
                // hope to find a taller wall.
                right--;
            }
        }

        // Return the largest container area found.
        return maxwater;
    }
};
```
