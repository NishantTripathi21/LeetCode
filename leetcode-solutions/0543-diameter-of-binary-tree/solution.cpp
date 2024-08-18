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
    int height(TreeNode*root){
        if(!root)return 0;
        int leftans=height(root->left);
        int rightans=height(root->right);
        return max(leftans,rightans)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int leftSideAns=diameterOfBinaryTree(root->left);
        int rightSideAns=diameterOfBinaryTree(root->right);
        int heights=height(root->left)+height(root->right);
        return max(leftSideAns,max(rightSideAns,heights));
        
    }
};
