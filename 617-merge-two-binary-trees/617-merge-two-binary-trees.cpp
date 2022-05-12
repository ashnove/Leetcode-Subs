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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL || root2 == NULL){
            if(root1 == root2){
                return NULL;
            }
            else if(root1){ 
                TreeNode* currentNode = new TreeNode(root1->val);
                currentNode->left = mergeTrees(root1->left, root2);
                currentNode->right = mergeTrees(root1->right, root2);
                return currentNode;
            }
            else {
                TreeNode* currentNode = new TreeNode(root2->val);
                currentNode->left = mergeTrees(root1, root2->left);
                currentNode->right = mergeTrees(root1, root2->right);
                return currentNode;
            }
        }
        TreeNode* currentNode = new TreeNode(root1->val + root2->val);
        currentNode->left = mergeTrees(root1->left, root2->left);
        currentNode->right = mergeTrees(root1->right, root2->right);
        return currentNode;
    }
};