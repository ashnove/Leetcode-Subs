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
    int letsFindKthSmallestElement(TreeNode* root, int& k){
        if(root == NULL) return -1;
        
        int res = letsFindKthSmallestElement(root->left, k);
        if(res != -1) return res;
        
        k--;
        if(k == 0) return root->val;
        
        return letsFindKthSmallestElement(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return letsFindKthSmallestElement(root, k);
    }
};