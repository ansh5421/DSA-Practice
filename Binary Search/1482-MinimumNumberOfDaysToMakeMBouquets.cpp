class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k) {
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                cnt++;
            }
            else {
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB += (cnt/k);
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m*k > n) return -1;
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (possible(bloomDay, mid, m, k)) {
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return lo;
    }
};
