class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minsum = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int currsum = 0;
            for(int j = i; j < nums.size(); j++){
                currsum += nums[j];
                int len = j - i + 1;

                if(len >= l && len <= r && currsum > 0){
                    minsum = min(minsum, currsum);
                }
            }
        }
        if(minsum == INT_MAX){
            return -1;
        }
        else{
            return minsum;
        }
    }
};