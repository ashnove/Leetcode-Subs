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
    int countGoodNodes(TreeNode* root, int maxVal = -10001){
        if(root == NULL) return 0;
        int ans = (root->val >= maxVal);
        maxVal = max(maxVal, root->val);
        return ans + countGoodNodes(root->left, maxVal) + countGoodNodes(root->right, maxVal);
    }
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root);
    }
};