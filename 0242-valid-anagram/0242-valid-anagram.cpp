class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> mpp;
        vector<char> mpp2;
        
        for(size_t i = 0; i < s.length(); i++){
            mpp.push_back(s[i]);
        }
        for(size_t j = 0; j < t.length(); j++){
            mpp2.push_back(t[j]);
        }
        sort(mpp.begin(), mpp.end());
        sort(mpp2.begin(), mpp2.end());

        return mpp == mpp2;
    }
};