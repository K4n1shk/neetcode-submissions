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

class Codec {
private:
    void serializeDfs(TreeNode* root, string& result){
        if(!root) {
            result += "#,";
            return;
        }
        result += to_string(root->val) + ",";
        serializeDfs(root->left, result);
        serializeDfs(root->right, result);
    }

    TreeNode* deserializeDfs(queue<string>& nodes){
        string val = nodes.front();
        nodes.pop();

        if(val == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeDfs(nodes);
        root->right = deserializeDfs(nodes);
        return root;
    }


public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeDfs(root,result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        string token;
        stringstream ss(data);
        while(getline(ss,token,',')){
            if(!token.empty()){
                nodes.push(token);
            }
        }
        return deserializeDfs(nodes);
    }
};
