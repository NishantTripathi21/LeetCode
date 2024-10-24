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
    void helper(TreeNode*root){
        if(!root)return;
        helper(root->left);
        helper(root->right);
        if(root->left){
            //save root->right because we are going to modify it
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=0;//point left to nullptr

            //traverse to last element of root->left and add this to first element of root->right
            TreeNode*curr=root;
            while(curr->right){
                curr=curr->right;
            }
            curr->right=temp;
        }
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};
