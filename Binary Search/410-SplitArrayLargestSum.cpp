class Solution {
public:
    int noOfSubArr(vector<int>& arr, int sum) {
        int arrCnt = 1;
        int currSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (currSum + arr[i] <= sum) {
                currSum += arr[i];
            }
            else {
                arrCnt++;
                currSum = arr[i];
            }
        }
        return arrCnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);

        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (noOfSubArr(nums, mid) > k) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};
