class Solution {
public:
    bool isPalindrome(int x) {
        long long rem, revNum = 0;
        int realNum = x;

        if (x < 0) {
            return false;
        }

        while (x > 0) {
            rem = x % 10;
            revNum = revNum * 10 + rem;
            x /= 10;
        }

        if (realNum == revNum) {
            return true;
        }
        else {
            return false;
        }
    }
};
