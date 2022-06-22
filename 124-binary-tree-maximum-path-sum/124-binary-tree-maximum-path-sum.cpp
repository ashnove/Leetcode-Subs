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
    int ans = -1001;
    int helper(TreeNode* root){
        if(root == NULL) return 0;
        int leftMaxPath = max(helper(root->left), 0);
        int rightMaxPath = max(helper(root->right), 0);
        ans = max(ans, leftMaxPath + rightMaxPath + root->val);
        return max(leftMaxPath, rightMaxPath) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};