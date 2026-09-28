#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> mpp;
        mpp[0] = 1; 
        
        int presum = 0;
        int cnt = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            presum += nums[i]; 
            
            int remove = presum - k;
            
            if (mpp.find(remove) != mpp.end()) {
                cnt += mpp[remove];
            }
            
            mpp[presum]++;
        }
        
        return cnt;
    }
};
