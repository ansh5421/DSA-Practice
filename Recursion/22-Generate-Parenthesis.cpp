class Solution {
public:
    void genPar(string s, int opng, int clng, int n, vector<string>& ans){
        if (clng == n) {
            ans.push_back(s);
            return;
        }
        if (opng < n) genPar(s+"(", opng+1, clng, n, ans);
        if (opng > clng) genPar(s+")", opng, clng+1, n, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        genPar("", 0, 0, n, ans);
        return ans;
    }
};
