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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int low = 0, int high = -10) {
        if(high == -10) high = preorder.size() - 1;
        if(idx == preorder.size() || low > high) return NULL;
        TreeNode* currentNode = new TreeNode(preorder[idx]);
        int pos = 0;
        for(int i = low; i <= high; i++){
            if(preorder[idx] == inorder[i]){
                pos = i;
                break;
            }
        }
        idx++;
        // cout << low << " " << pos << " " << high << endl;
        currentNode->left = buildTree(preorder, inorder, low, pos - 1);
        currentNode->right = buildTree(preorder, inorder, pos + 1, high);
        return currentNode;
    }
};