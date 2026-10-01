class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int count = 1, maxCnt = 1;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-1; i++) {
            if (nums[i+1] == nums[i]+1) {
                count++;
                maxCnt = max(count, maxCnt);
            }
            else if (nums[i] == nums[i+1]) continue;
            else {
                count = 1;
            }
        }
        return maxCnt;

    }
};
