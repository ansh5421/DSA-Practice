class Solution {
public:
    int maxArea(vector<int>& height) {
        int lP = 0, rP = height.size() - 1, maxWater = 0;

        while (lP < rP) {
            int wd = rP - lP;
            int ht = min(height[lP], height[rP]);
            int area = wd * ht;
            maxWater = max(maxWater, area);

            height[lP] < height[rP] ? lP++ : rP--;
        }
        return maxWater;
    }
};
