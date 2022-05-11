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
    bool check(TreeNode* rootL, TreeNode* rootR){
        if(rootL == NULL || rootR == NULL){
            return rootL == rootR;
        }
        if(rootL->val != rootR->val) return false;
        else return check(rootL->left, rootR->right) && check(rootL->right, rootR->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return 1;
        return check(root->left, root->right);
    }
};