class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            int swapp = 0;
            for (int j = 0; j < nums.size()-1; j++) {
                if (nums[j] > nums[j+1]) {
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                    swapp++;
                }
            }
            if (swapp == 0) break;
        }
    }
};
