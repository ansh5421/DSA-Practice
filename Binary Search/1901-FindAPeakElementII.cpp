class Solution {
public:
    int maxElementIdx(vector<vector<int>>& mat, int col) {
        int maxVal = -1;
        int idx = -1;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][col] > maxVal) {
                maxVal = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int lo = 0, hi = m - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int maxEleRow = maxElementIdx(mat, mid);
            int left = mid - 1 >= 0 ? mat[maxEleRow][mid-1] : -1;
            int right = mid + 1 < m ? mat[maxEleRow][mid+1] : -1;

            if (mat[maxEleRow][mid] > left && mat[maxEleRow][mid] > right) return {maxEleRow, mid};
            else if (mat[maxEleRow][mid] < left) hi = mid - 1;
            else lo = mid + 1;
        }
        return {-1, -1};
    }
};
