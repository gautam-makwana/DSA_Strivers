class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length()) return false;
        int r = 0;
        int m = 0;

        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());

        while(r < ransomNote.length() && m < magazine.length()){
            if(ransomNote[r] == magazine[m]){
                r++;
                m++;
            }else{
                m++;
            }
        }
        return r == ransomNote.length();
    }
};