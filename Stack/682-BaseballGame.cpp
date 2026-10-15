class Solution {
public:
    int calPoints(vector<string>& s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == "D") {
                st.push(st.top()*2);
            }
            else if (s[i] == "C") {
                st.pop();
            }
            else if (s[i] == "+") {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.push(val1);
                st.push(val1 + val2);
            }
            else {
                st.push(stoi(s[i]));
            }
        }
        int ans = 0;
        while (st.size() > 0) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
