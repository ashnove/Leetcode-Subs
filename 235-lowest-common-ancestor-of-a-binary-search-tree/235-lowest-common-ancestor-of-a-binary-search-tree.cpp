/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int forLeft = p->val;
        int forRight = q->val;
        if(forLeft > forRight) swap(forLeft, forRight);
        if(forRight < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(forLeft > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};