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
    int height(TreeNode* root){
        if(!root)return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
    bool isBalanced1=true;
    int heightModified(TreeNode*root){
        if(!root)return 0;
        int leftH=heightModified(root->left);
        int rightH=heightModified(root->right);
        int ans=max(leftH,rightH)+1;
        if(abs(leftH - rightH) > 1 && isBalanced1) {
            isBalanced1 = false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        // if(!root)return true;
        // // current node
        // int leftHeight=height(root->left);
        // int rightHeight=height(root->right);
        // int diff=abs(leftHeight-rightHeight);
        // bool currNodeAns=diff<=1;
        // //recussive calls
        // bool left=isBalanced(root->left);
        // bool right=isBalanced(root->right);
        // return left&&right&&currNodeAns?true:false;
        heightModified(root);
        return isBalanced1;
    }
};
