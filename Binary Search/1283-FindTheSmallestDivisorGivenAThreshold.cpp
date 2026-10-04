class Solution {
public:
    int resultSum(vector<int> arr, int n) {
        int sum = 0;
        for (int num : arr) {
            sum += (num + n - 1)/n;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int i = 1, j = 0;
        for (int num : nums) {
            j = max(j, num);
        }
        int ans = j;

        while (i <= j) {
            int mid = i + (j-i)/2;
            if (resultSum(nums, mid) <= threshold) {
                ans = mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        return ans;
    }
};
