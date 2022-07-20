/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* prev = NULL;
            int nodeCount = q.size();
            for(int i = 0; i < nodeCount; i++){
                if(prev){
                    prev->next = q.front();
                }
                prev = q.front();
                if(prev->left) q.push(prev->left);
                if(prev->right) q.push(prev->right);
                q.pop();
            }
            prev->next = NULL; 
        }
        return root;
    }
};