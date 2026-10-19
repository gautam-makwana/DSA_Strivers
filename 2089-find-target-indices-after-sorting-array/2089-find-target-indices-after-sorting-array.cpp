#include <vector>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller_count = 0;
        int equal_count = 0;
        for (int num : nums) {
            if (num < target) {
                smaller_count++;
            } else if (num == target) {
                equal_count++;
            }
        }
        vector<int> ans;
        for (int i = 0; i < equal_count; i++) {
            ans.push_back(smaller_count + i);
        }
        
        return ans;
    }
};
