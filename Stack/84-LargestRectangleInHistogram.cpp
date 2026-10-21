class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> st;
        vector<int> nSI(n);

        for (int i = n-1; i >= 0; i--) {
            while (st.size() > 0 && heights[st.top()] >= heights[i]) st.pop();
            if (st.size() != 0) nSI[i] = st.top();
            else nSI[i] = n;
            st.push(i);
        }
        while (st.size() != 0) st.pop();
        vector<int> pSI(n);

        for (int i = 0; i < n; i++) {
            while (st.size() > 0 && heights[st.top()] >= heights[i]) st.pop();
            if (st.size() != 0) pSI[i] = st.top();
            else pSI[i] = -1;
            st.push(i);
        }
        
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = nSI[i] - pSI[i] - 1;
            maxArea = max(maxArea, height*width);
        }
        return maxArea;
    }
};
