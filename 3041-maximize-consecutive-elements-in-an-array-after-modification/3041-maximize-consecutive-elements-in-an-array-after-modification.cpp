class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        int ans = 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++){
            int x = nums[i];
            mpp[x+1] = max(mpp[x+1], mpp[x] + 1);
            mpp[x] = max(mpp[x], mpp[x - 1] + 1);
            ans = max({ans, mpp[x], mpp[x+1]});
        }
        
        return ans;
    }
};