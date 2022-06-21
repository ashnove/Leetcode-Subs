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
    bool isValidBST(TreeNode* root, long long low = (long long)INT_MIN - 1, long long high = (long long)INT_MAX + 1) {
        if(root == NULL) return 1;
        long long node = root->val;
        if(node >= high || node <= low) return 0;
        return isValidBST(root->left, low, node) && isValidBST(root->right, node, high);
    }
};