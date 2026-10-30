class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int currentsum = 0;

        for(int i = 0; i < nums.size(); i++){
            currentsum += nums[i];
            ans.push_back(currentsum);
        }
        return ans;
    }
};