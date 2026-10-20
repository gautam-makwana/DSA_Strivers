class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            if (val < 0) {
                val = -val;
            }
            
            int idx = val - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};
