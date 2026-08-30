class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return chars.size();
        int i = 0, j = 0;
        int num = 0;
        string s = "";
        while (j < chars.size()) {
            if (chars[i] == chars[j]) j++;
            else {
                num = j-i;
                s.push_back(chars[i]);
                if (num != 1) s += to_string(num);
                i = j;
            }
        }
        num = j-i;
        s.push_back(chars[i]);
        if (num != 1) s += to_string(num);

        vector<char> ans;
        for (char ch : s) ans.push_back(ch);
        chars = ans;
        return chars.size();
    }
};
