class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int totalWater = 0;
        while (i < j) {
            if (height[i] <= height[j]) {
                if (height[i] >= leftMax) {
                    leftMax = height[i];
                } else {
                    totalWater += leftMax - height[i];
                }
                i++;
            } else {
                if (height[j] >= rightMax) {
                    rightMax = height[j];
                } else {
                    totalWater += rightMax - height[j];
                }
                j--;
            }
        }
        return totalWater;
    }
};