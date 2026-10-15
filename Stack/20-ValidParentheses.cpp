class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;
        stack<char> ch;
        int i = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                ch.push(s[i]);
            }
            else {
                if (ch.size() == 0) return false;
                else if (s[i] == ')' and ch.top() == '(') ch.pop();
                else if (s[i] == ']' and ch.top() == '[') ch.pop();
                else if (s[i] == '}' and ch.top() == '{') ch.pop();
                else return false;
            }
        }
        return (ch.size() == 0);
    }
};
