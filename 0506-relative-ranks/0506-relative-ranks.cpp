class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }
        vector<string> ans(score.size());
        int place = 1;
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();

            if(place == 1){
                ans[idx] = "Gold Medal";
            }else if(place == 2){
                ans[idx] = "Silver Medal";
            }else if(place == 3){
                ans[idx] = "Bronze Medal";
            }else{
                ans[idx] = to_string(place);
            }
            place++;
        }
        return ans;
    }
};