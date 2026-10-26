class Solution {
public:
    int findDays(vector<int>& arr, int cap) {
        int days = 1, load = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (load + arr[i] > cap) {
                days++;
                load = arr[i];
            }
            else load += arr[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (findDays(weights, mid) <= days) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};
