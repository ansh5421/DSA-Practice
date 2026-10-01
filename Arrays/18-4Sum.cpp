class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;


            for (int j = i+1; j < n-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;


                int lP = j+1, rP = n-1;
                
                while (lP < rP) {
                    long long sum = (long long)nums[i] + nums[j] + nums[lP] + nums[rP];
                    if (sum < target) {
                        lP++;
                    }
                    else if (sum > target) {
                        rP--;
                    }
                    else {
                        ans.push_back({nums[i], nums[j], nums[lP], nums[rP]});

                        while (lP < rP && nums[lP] == nums[lP + 1]) lP++;

                        while (lP < rP && nums[rP] == nums[rP - 1]) rP--;

                        lP++;
                        rP--;
                    }
                }
            }
        }
        return ans;
    }
};
