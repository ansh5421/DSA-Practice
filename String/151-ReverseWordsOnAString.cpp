class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        for (int j = 0; j < s.size(); j++) {
            string word = "";
            while (j < s.size() && s[j] != ' ') {
                word += s[j];
                j++;
            }
            reverse(word.begin(), word.end());
            if (word.length() > 0) ans += " " + word;
        }
        return ans.substr(1);
    }
};
