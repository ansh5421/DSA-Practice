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
    class Quad {
    public:
        long long mx;
        long long mn;
        long long sum;
        bool isBST;
    };
    int maxSum;
    Quad solve(TreeNode* root) {
        if (root == NULL) return {LLONG_MIN, LLONG_MAX, 0, true};
        Quad left = solve(root->left);
        Quad right = solve(root->right);
        long long val = root->val;
        long long mx = max(val, max(left.mx, right.mx));
        long long mn = min(val, min(left.mn, right.mn));
        int sum = val + left.sum + right.sum;
        bool isBST = val < right.mn && val > left.mx && left.isBST && right.isBST;
        if (isBST) maxSum = max(sum, maxSum);
        return {mx, mn, sum, isBST};
    }

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        solve(root);
        return maxSum;
    }
};
