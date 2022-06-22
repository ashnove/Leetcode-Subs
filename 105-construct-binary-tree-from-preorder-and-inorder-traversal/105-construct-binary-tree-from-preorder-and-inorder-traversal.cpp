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
    int idx = 0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int low, int high, unordered_map<int,int>& hash){
        if(idx == preorder.size() || low > high) return NULL;
        TreeNode* currentNode = new TreeNode(preorder[idx]);
        int pos = hash[preorder[idx]];
        idx++;
        currentNode->left = helper(preorder, inorder, low, pos - 1, hash);
        currentNode->right = helper(preorder, inorder, pos + 1, high, hash);
        return currentNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> hash;
        for(int i = 0; i < inorder.size(); i++){
            hash[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, preorder.size() - 1, hash);
    }
};