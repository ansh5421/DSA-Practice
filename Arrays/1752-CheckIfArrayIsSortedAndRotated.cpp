class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[(i+1)%nums.size()]) {
                cnt++;
            }
        }
        return cnt <= 1;
    }
};
