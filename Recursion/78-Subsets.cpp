class Solution {
public:
    void powerSet(int idx, vector<int> ans, vector<int>& nums, vector<vector<int>>& finalAns) {
        if (idx == nums.size()) {
            finalAns.push_back(ans);
            return;
        }
        powerSet(idx+1, ans, nums, finalAns);
        ans.push_back(nums[idx]);
        powerSet(idx+1, ans, nums, finalAns);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalAns;
        vector<int> ans;
        powerSet(0, ans, nums, finalAns);
        return finalAns;
    }
};
