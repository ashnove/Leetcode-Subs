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
    vector<TreeNode*> createBST(int left, int right){
        if(left > right) return {NULL};
        
        vector<TreeNode*> bstList;
        for(int i = left; i <= right; i++){
            TreeNode* root = new TreeNode(i);
            vector<TreeNode*> leftSubtrees = createBST(left, i - 1);
            vector<TreeNode*> rightSubtrees = createBST(i + 1, right);
            
            for(auto leftSubtree : leftSubtrees){
                for(auto rightSubtree: rightSubtrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSubtree;
                    root->right = rightSubtree;
                    bstList.push_back(root);
                }
            }
        }
        return bstList;        
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> bstList;
        bstList = createBST(1, n);
        return bstList;
    }
};