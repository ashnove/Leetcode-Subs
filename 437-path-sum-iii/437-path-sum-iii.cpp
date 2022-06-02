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
    int pathSum(TreeNode* root, int targetSum) {
        map<long long int,int> hash;
        long long int sum = 0;
        hash[0] = 1;
        return pathSumUtil(root, targetSum, sum, hash);
    }
    
    int pathSumUtil(TreeNode* root, int targetSum, long long int& sum, map<long long int,int>& hash){
        if(root == NULL) return 0;
        sum += root->val;
        int ans = hash[sum - targetSum];
        hash[sum]++;
        int leftPaths = pathSumUtil(root->left, targetSum, sum, hash);
        int rightPaths = pathSumUtil(root->right, targetSum, sum, hash);
        
        hash[sum]--;
        sum -= root->val;
        return leftPaths + rightPaths + ans;
    }
    
};