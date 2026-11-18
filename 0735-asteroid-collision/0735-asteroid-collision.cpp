class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(int i = 0; i < asteroids.size(); i++){
            if(st.empty() || asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            else{
                while(true){
                    if(st.empty()){
                        st.push(asteroids[i]);
                        break;
                    }
                    int val = st.top();
                    if(val < 0){
                        st.push(asteroids[i]);
                        break;
                    }
                    else if(abs(asteroids[i]) == val){
                        st.pop();
                        break;
                    }
                    else{
                        if(abs(asteroids[i]) > val){
                            st.pop();
                            
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};