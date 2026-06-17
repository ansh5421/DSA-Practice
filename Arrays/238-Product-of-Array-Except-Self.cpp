class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            answer[i] = answer[i-1] * nums[i-1];
        }

        int Suffix = 1;
        for (int j = nums.size()-2; j >= 0; j--) {
            Suffix *= nums[j+1];
            answer[j] *= Suffix;
        }
        return answer;
    }
};
