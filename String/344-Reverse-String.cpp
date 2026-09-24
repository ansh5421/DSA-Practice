class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 1) return;
        reverse(s.begin(), s.end());
    }
};
