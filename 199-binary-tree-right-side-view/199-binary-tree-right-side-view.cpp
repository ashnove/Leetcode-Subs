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
    void traverse(TreeNode* root, int depth, vector<int>&rightSideViewNodes){
        if(root == NULL) return;
        
        if(rightSideViewNodes.size() == depth){
            rightSideViewNodes.push_back(root->val);
        }
        traverse(root->right, depth + 1, rightSideViewNodes);
        traverse(root->left, depth + 1, rightSideViewNodes);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSideViewNodes;
        traverse(root, 0, rightSideViewNodes);
        return rightSideViewNodes;
    }
};