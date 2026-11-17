class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        stack<int> st;

        for(auto num : nums2){
            while(!st.empty() && num > st.top()){
                mpp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> ans;
        for(auto num : nums1){
            if(mpp.count(num)){
                ans.push_back(mpp[num]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};