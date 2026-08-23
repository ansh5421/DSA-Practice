class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<bool> row(r, false);
        vector<bool> col(c, false);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < row.size(); i++) {
            if (row[i]) {
                for (int j = 0; j < c; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < col.size(); j++) {
            if (col[j]) {
                for (int i = 0; i < r; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
