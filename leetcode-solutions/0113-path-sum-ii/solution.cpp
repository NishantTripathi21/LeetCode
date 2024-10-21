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
        if(root == NULL){ 
            return;
        }
        temp.push_back(root->val);
        // If we're at a leaf node, check if the path sum equals targetSum
        if (!root->left && !root->right){
            if(targetSum == root->val){
                ans.push_back(temp);
            }
        }
        else{
            Helper(root->left, targetSum - root->val,ans,temp);
            Helper(root->right, targetSum - root->val ,ans,temp);
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
