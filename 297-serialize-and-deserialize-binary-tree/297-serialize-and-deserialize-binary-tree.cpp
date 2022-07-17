/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "X";
        string LeftSerialize = serialize(root->left);
        string RightSerialize = serialize(root->right);
        return to_string(root->val) + "," + LeftSerialize + "," + RightSerialize;
    }

    // Decodes your encoded data to tree.
    int idx = 0;
    TreeNode* deserialize(string data) {
        if(data[idx] == 'X') {
            idx+=2;
            return NULL;
        }
        string current = "";
        bool neg = 0;
        while(data[idx] != ','){
            if(data[idx]=='-') neg = 1;
            else current += data[idx];
            idx++;
        }
        idx++;
        int val = (neg ? -1 : 1) * stoi(current);
        TreeNode* node = new TreeNode(val);
        node->left = deserialize(data);
        node->right = deserialize(data);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));