/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<TreeNode*>& ans) {
        if (root == NULL) return;
        ans.push_back(root);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        dfs(root, ans);
        int n = ans.size();
        for (int i = 0; i < n; i++) {
            if (i < n - 1) ans[i]->right = ans[i+1];
            ans[i]->left = NULL;
        }
    }
};
