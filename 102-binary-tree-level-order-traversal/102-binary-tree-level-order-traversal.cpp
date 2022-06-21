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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> levelOrderNodes;
        levelOrderNodes.push_back({});
        queue<TreeNode*> level;
        level.push(root);
        level.push(NULL);
        while(!level.empty()){
            if(level.front()){
                TreeNode* currentNode = level.front();
                levelOrderNodes.back().push_back(currentNode->val);
                level.pop();
                if(currentNode->left) level.push(currentNode->left);
                if(currentNode->right) level.push(currentNode->right);
            }
            else{
                level.pop();
                if(!level.empty()){
                    level.push(NULL);
                    levelOrderNodes.push_back({});
                }
            }
        }
        return levelOrderNodes;
    }
};