class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return false;
        sort(nums.begin(), nums.end());
        bool isDuplicate = false;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) {
                isDuplicate = true;
                break;
            }
        }
        return isDuplicate;
        
    }
};
