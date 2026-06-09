class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, result = 0;

        for (int i = 0; i < nums.size(); i++){
            if ( freq == 0 ) {
                result = nums[i];
            }
            if ( result == nums[i] ) {
                freq++;
            }
            else {
                freq--;
            }
        }

        return result;
        
    }
};
