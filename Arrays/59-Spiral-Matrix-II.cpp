class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int minR = 0, minC = 0, maxR = n-1, maxC = n-1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        int a = 1;

        while (a <= n*n) {
            for (int i = minC; i <= maxC; i++) {
                ans[minR][i] = a++;
            }
            minR++;
            for (int i = minR; i <= maxR; i++) {
                ans[i][maxC] = a++;
            }
            maxC--;
            for (int i = maxC; i >= minC; i--) {
                ans[maxR][i] = a++;
            }
            maxR--;
            for (int i = maxR; i >= minR; i--) {
                ans[i][minC] = a++;
            }
            minC++;
        }
        return ans;
    }
};
