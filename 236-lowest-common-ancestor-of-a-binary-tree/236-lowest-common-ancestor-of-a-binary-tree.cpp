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
        if(root == NULL) return NULL;
        
        if(p == root || q == root){
            return root;            // if either of p or q matches that's the lca;
        }
        
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q); // fetch lca from left subtree;
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q); // fetch lca from right subtree;
        
        if(leftLCA && rightLCA) return root; // before finding the lca, leftLCA and rightLCA brings the nodes of which we are here to find lca. If both are not null, this is the first splitting point hence root = LCA;
        return (leftLCA ? leftLCA : rightLCA); // if one of them is NULL, then other one is just floating the LCA to the top;
    }
};