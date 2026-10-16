class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ans(heights.size(), 0);
        stack<int> st;

        for (int i = heights.size()-1; i >= 0; i--) {
            while (st.size() > 0 && st.top() <= heights[i]) {
                st.pop();
                ans[i]++;
            }
            if (st.size() != 0) ans[i]++;
            st.push(heights[i]);
        }
        return ans;
    }
};
