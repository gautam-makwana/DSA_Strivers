#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long reqTime(vector<int>& arr, int h){
        long long totalhours = 0; 
        int n = arr.size();

        for(int i = 0; i < n; i++){
            totalhours += ceil((double)arr[i] / h);
        }
        return totalhours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalHours = reqTime(piles, mid);

            if(totalHours <= h){
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
    return ans;
    }
};
