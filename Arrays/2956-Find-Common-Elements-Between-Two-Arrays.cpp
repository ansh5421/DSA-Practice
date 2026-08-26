class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2);
        int a1 = 0, a2 = 0;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    a1++;
                    break;
                }
            }
        }

        for (int i = 0; i < nums2.size(); i++) {
            for (int j = 0; j < nums1.size(); j++) {
                if (nums2[i] == nums1[j]) {
                    a2++;
                    break;
                }
            }
        }
        ans[0] = a1;
        ans[1] = a2;
        return ans;
    }
};
