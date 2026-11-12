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
    int dia;
    int diameter(TreeNode* root) {
        if (root == NULL) return 0;
        int leftlevel = diameter(root->left);
        int rightlevel = diameter(root->right);
        dia = max(dia, leftlevel + rightlevel);
        return 1 + max(leftlevel, rightlevel);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dia = 0;
        diameter(root);
        return dia;
    }
};
