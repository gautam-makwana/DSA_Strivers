class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) return false;
        for(int i = 0; i < ransomNote.length(); i++){
            char target = ransomNote[i];
            bool found = false;

            for(int j = 0; j < magazine.length(); j++){
                if(magazine[j] == target){
                    magazine[j] = ' ';
                    found = true;
                    break;
                }
            }if(!found) return false;
        }
        return true;
    }
};