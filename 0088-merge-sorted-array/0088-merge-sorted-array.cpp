class Solution {
public:
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        vector<int> ans(k);

        while(j >= 0)
        { 
            if(i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                ans.push_back(nums1[k]);
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                ans.push_back(nums1[k]);                
                j--;
            }
            k--;
        }
        return ans;
    }
};