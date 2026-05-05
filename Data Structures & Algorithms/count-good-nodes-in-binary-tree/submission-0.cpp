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
private:
    int dfs(TreeNode* root, int maxVal){
        if(!root) return 0;
        int res = (root->val >= maxVal) ? 1 : 0;
        maxVal = max(root->val,maxVal);
        res += dfs(root->left,maxVal);
        res += dfs(root->right,maxVal);
        return res; 
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};
