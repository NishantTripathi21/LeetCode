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
    int helper(TreeNode* root, int &maxSum){
        if(!root)return 0;
        int currValue=root->val;
        int leftAns=helper(root->left,maxSum);
        int rightAns=helper(root->right,maxSum);
        int curr=max(currValue,max(currValue+leftAns,currValue+rightAns));//store maximum sum till currNode.
        maxSum=max(maxSum,leftAns+rightAns+currValue);//if current Node forms greatest sum.
        maxSum=max(maxSum,curr);//store the maximum sum till now.
        return curr;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        helper(root,maxSum);
        return maxSum;
    }
};
