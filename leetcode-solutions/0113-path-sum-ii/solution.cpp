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
    void Helper(TreeNode*root,int targetSum,vector<vector<int>>&ans,vector<int>&temp){
        if (root == nullptr){ 
            return ;  // If the tree is empty, there's no path
        }
        temp.push_back(root->val);
        // If we're at a leaf node, check if the path sum equals targetSum
        if (root->left == nullptr && root->right == nullptr) {
            if(targetSum == root->val){
                ans.push_back(temp);
            }
        }
        else{
             int remainingSum = targetSum - root->val;
            Helper(root->left, remainingSum,ans,temp);
            Helper(root->right, remainingSum,ans,temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        Helper(root,targetSum,ans,temp);
        return ans;
        
    }
};
