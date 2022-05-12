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
    TreeNode* createBST(int low, int high, vector<int>& nums){
        if(low > high) return NULL;
        int mid = low + (high - low) / 2;
        TreeNode* currentRoot = new TreeNode(nums[mid]);
        currentRoot->left = createBST(low, mid - 1, nums);
        currentRoot->right = createBST(mid + 1, high, nums);
        return currentRoot;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(0, nums.size() - 1, nums);
    }
};