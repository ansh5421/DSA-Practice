class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minR = 0, minC = 0, maxR = matrix.size()-1, maxC = matrix[0].size()-1;
        vector<int> ans;
        while(minR <= maxR && minC <= maxC) {
            for (int i = minC; i <= maxC; i++) {
            ans.push_back(matrix[minR][i]);
            }
            minR++;
            if(minR > maxR || minC > maxC) break;
            for (int i = minR; i <= maxR; i++) {
                ans.push_back(matrix[i][maxC]);
            }
            maxC--;
            if(minR > maxR || minC > maxC) break;
            for (int i = maxC; i >= minC; i--) {
                ans.push_back(matrix[maxR][i]);
            }
            maxR--;
            if(minR > maxR || minC > maxC) break;
            for (int i = maxR; i >= minR; i--) {
                ans.push_back(matrix[i][minC]);
            }
            minC++;
            if(minR > maxR || minC > maxC) break;
        }
        return ans;
    }
};
