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
    void rangeElement(TreeNode* root, vector<int>& ans, int low, int high) {
        if (root == NULL) return;
        if (root->val <= high && root->val >= low) {
            ans.push_back(root->val);
        }
        rangeElement(root->left, ans, low, high);
        rangeElement(root->right, ans, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
        rangeElement(root, ans, low, high);
        int sum = accumulate(ans.begin(), ans.end(), 0);
        return sum;
    }
};
