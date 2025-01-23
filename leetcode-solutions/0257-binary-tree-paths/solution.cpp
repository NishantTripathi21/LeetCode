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
    void findPaths(TreeNode* root, vector<string>& result, string currentPath) {
        if (!root) return;

        currentPath += to_string(root->val);
        if (!root->left && !root->right) {
            result.push_back(currentPath);
            return;
        }
        currentPath += "->"; 
        findPaths(root->left, result, currentPath);
        findPaths(root->right, result, currentPath);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        findPaths(root,result,"");
        return result;
    }
};
