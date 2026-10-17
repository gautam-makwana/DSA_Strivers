class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map <int, int> mpp;
        for(auto num : nums1){
            mpp[num]++;
        }

        for(auto num : nums2){
            auto it = mpp.find(num);

            if(it != mpp.end()){
                ans.push_back(num);
                mpp.erase(it);
            }
        }

        return ans;
    }
};