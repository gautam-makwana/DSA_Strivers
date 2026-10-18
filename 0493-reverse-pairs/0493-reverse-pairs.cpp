#include <vector>

using namespace std;

class Solution {
private:
    void merge(vector<int> &arr, vector<int> &temp, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        int index = low;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[index++] = arr[left++];
            } else {
                temp[index++] = arr[right++];
            }
        }
        
        while (left <= mid) {
            temp[index++] = arr[left++];
        }
        while (right <= high) {
            temp[index++] = arr[right++];
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i];
        }
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int count = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }

    int mergesort(vector<int> &arr, vector<int> &temp, int low, int high) {
        if (low >= high) return 0;
        
        int mid = low + (high - low) / 2; 
        
        int count = 0;
        count += mergesort(arr, temp, low, mid);
        count += mergesort(arr, temp, mid + 1, high);
        count += countPairs(arr, low, mid, high);
        merge(arr, temp, low, mid, high);
        
        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        vector<int> temp(n); 
        return mergesort(nums, temp, 0, n - 1);
    }
};
