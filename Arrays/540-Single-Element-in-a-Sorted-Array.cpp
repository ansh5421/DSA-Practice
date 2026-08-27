class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            int f = mid, s = mid;
            if (nums[mid] == nums[mid-1]) f = mid-1;
            else s = mid+1;
            if ((f-low)%2==1) high = f-1;
            else low = s+1;
        }
        return -1;
    }
};
