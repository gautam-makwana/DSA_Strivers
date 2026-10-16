class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
            string ans = "1";
        for (size_t i = 1; i < n; i++) {
            int count = 1;
            string next_ans;

            for (size_t j = 0; j < ans.length(); j++) {
                if(j + 1 < ans.length() && ans[j] == ans[j+1]){
                    count++;
                }else{
                    next_ans += to_string(count) + ans[j];
                    count = 1;
                }
            }
            ans = next_ans;
        }
        return ans;
    }
};