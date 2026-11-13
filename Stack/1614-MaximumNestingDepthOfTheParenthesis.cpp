class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char> st;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' or s[i] == ')') {
                if (s[i] == '(') {
                    st.push(s[i]);
                    cnt = max(cnt, (int)st.size());
                }
                else {
                    if (st.top() == '(') {
                        if (st.size() != 0) st.pop();
                    }
                }
            }
        }
        return cnt;
    }
};
