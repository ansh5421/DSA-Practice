class Solution {
public:
    string largestOddNumber(string num) {
        while (num.size() > 0) {
            if (num[num.size()-1] % 2 == 1) return num;
            else {
                num.pop_back();
            }
        }
        return "";
    }
};
