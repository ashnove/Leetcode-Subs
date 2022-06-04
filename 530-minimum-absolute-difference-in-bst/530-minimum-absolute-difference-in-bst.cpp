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
    void traverse(TreeNode* root, int& prev, int& ans){
        if(root == NULL) return;
        
        traverse(root->left, prev, ans);
        ans = min(ans, root->val - prev);
        prev = root->val;
        traverse(root->right, prev, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev = -2001;
        int ans = 2001;
        traverse(root, prev, ans);
        return ans;
    }
};