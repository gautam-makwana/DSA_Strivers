class Solution {
public:
    char findTheDifference(string s, string t) {
        int i = 0;
        char result = 0;
        while (s[i] != '\0') {
            result ^= s[i];
            i++;
        }
        i = 0;
        while (t[i] != '\0') {
            result ^= t[i];
            i++;
        }
        return result;
    }
};