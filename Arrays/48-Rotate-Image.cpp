class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int c = matrix.size(), r = matrix[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < r; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
