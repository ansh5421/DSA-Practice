class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            int currSum = 0;
            for (int j = i; j < n; j++) {
                currSum += nums[j];
                int subArrLen = j - i + 1;
                if (subArrLen >= l && subArrLen <= r && currSum > 0) {
                    minSum = min(minSum, currSum);
                }
            }
        }
        return (minSum == INT_MAX) ? -1 : minSum;
    }
};
