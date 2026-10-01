class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int lP = i+1, rP = nums.size()-1;
            while (lP < rP) {
                if (nums[i] + nums[lP] + nums[rP] < 0) {
                    lP++;
                }
                else if (nums[i] + nums[lP] + nums[rP] > 0) {
                    rP--;
                }
                else {
                    ans.push_back(vector<int>{nums[i], nums[lP], nums[rP]});
                    lP++;
                    rP--;

                    while (lP < rP && nums[lP] == nums[lP - 1]) lP++;

                    while (lP < rP && nums[rP] == nums[rP + 1]) rP--;
                }
            }
        }
        return ans;
    }
};
