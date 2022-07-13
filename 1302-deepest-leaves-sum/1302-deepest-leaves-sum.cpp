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
    int sum(TreeNode* root, int* height){
        int leftHeight = 0, rightHeight = 0;
        if(root == nullptr){
            *height = 0;
            return 0;
        }
        
        int leftSum = sum(root->left, &leftHeight);
        int rightSum = sum(root->right, &rightHeight);
        *height = max(leftHeight, rightHeight) + 1;

        if(leftHeight == rightHeight)
            return leftSum + rightSum + (!root->left&&!root->right ? root->val : 0);
        else if(leftHeight > rightHeight)
            return leftSum + (!root->left? root->val : 0);
        else 
            return rightSum + (!root->right ? root->val : 0);
    }
    int deepestLeavesSum(TreeNode* root) {
        int h = 0;
        return sum(root, &h);
    }
};