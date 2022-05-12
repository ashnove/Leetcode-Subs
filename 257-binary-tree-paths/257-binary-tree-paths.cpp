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
    void findAllPaths(TreeNode* root, string onePath, vector<string>& allPaths){
        if(root == NULL) return;    
        if(root->left == NULL && root->right == NULL){
            allPaths.push_back(onePath + (onePath.size() ? "->" : "") + to_string(root->val));
            return;
        }
        findAllPaths(root->left, onePath + (onePath.size() ? "->" : "") + to_string(root->val), allPaths);
        findAllPaths(root->right, onePath + (onePath.size() ? "->" : "") + to_string(root->val), allPaths);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string onePath = "";
        vector<string> allPaths;
        findAllPaths(root, onePath, allPaths);
        return allPaths;
    }
};