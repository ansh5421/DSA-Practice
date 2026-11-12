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
    class Pair {
    public:
        TreeNode* node;
        int level;
        Pair(TreeNode* node, int level) {
            this->node = node;
            this->level = level;
        }
    };

    int levels(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans(n, vector<int>(0));
        queue<Pair> q;
        if (root != NULL) q.push({root, 0});
        while (q.size() > 0) {
            Pair front = q.front();
            q.pop();
            TreeNode* node = front.node;
            int level = front.level;
            ans[level].push_back(node->val);
            if (node->left != NULL) q.push({node->left, level+1});
            if (node->right != NULL) q.push({node->right, level+1});
        }
        return ans;
    }
};
