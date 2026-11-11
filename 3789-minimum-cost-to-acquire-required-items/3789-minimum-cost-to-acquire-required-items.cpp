class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = min(cost1, costBoth);
        long long c2 = min(cost2, costBoth);
        long long cb = costBoth;

        if(c1 + c2 < cb){
            cb = c1 + c2;
        }

        if(need1 < need2) return cb * need1 + (need2 - need1) * c2;
        else return cb * need2 + (need1 - need2) * c1;
    }
};