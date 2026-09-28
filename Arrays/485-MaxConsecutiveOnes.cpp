class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int freq = 0;
        int maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                freq++;
                maxFreq = max(freq, maxFreq);
            }
            else {
                freq = 0;
            }

        }
        return maxFreq;
    }
};
