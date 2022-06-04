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
    int sumOfLeftLeaves(TreeNode* root) {
        
        //if root is NULL or root = leaf, we don't need to pursue that;
        if(root == NULL || (root->left==NULL&&root->right==NULL))
            return 0;
        
        //when left child is leaf, add it's value and get the sum from the right subtree;
        if( (!root->left) || (!root->left->right && !root->left->left)) 
            return (root->left ? root->left->val : 0) + sumOfLeftLeaves(root->right);
        
        // else get sum from both the subtrees
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};