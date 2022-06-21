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
    bool isValidBST(TreeNode* root, long long low = INT_MIN, long long high = INT_MAX) {
        if(root == NULL) return 1;
        long long node = root->val;
        if(node > high || node < low) return 0;
        return 1 && isValidBST(root->left, low, node - 1) && isValidBST(root->right, node + 1, high);
    }
};