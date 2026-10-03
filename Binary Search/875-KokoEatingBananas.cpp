class Solution {
public:
    bool check(vector<int> arr, int mid, int k) {
        long long totalHour = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalHour += (arr[i] + mid -1)/mid;
        }
        return totalHour <= k;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1, j = *max_element(piles.begin(), piles.end());
        int ans = j;

        while (i <= j) {
            int mid = i + (j-i)/2;

            if (check(piles, mid, h)) {
                ans = mid;
                j = mid-1;
            }
            else i = mid+1;
            
        }
        return ans;
    }
};
