class Solution {
public:
    int minMoves(vector<int>& nums) {
        int small = INT_MAX;
        for(int n : nums){
            small = min(n, small);
        }

        int minmove = 0;
        for(int i : nums){
            minmove += i - small;
        }

        return minmove;
    }
};