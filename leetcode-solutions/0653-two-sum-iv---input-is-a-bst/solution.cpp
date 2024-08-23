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
    void storeInorder(vector<int>&ans,TreeNode*root){
        if(!root)return;
        //LNR traversal
        storeInorder(ans,root->left);
        ans.push_back(root->val);
        storeInorder(ans,root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        storeInorder(ans,root);
        int start=0;
        int end=ans.size()-1;
        while(start<end){
            if(ans[start]+ans[end]==k){
                return true;
            }
            else if(ans[start]+ans[end]<k){
                start++;
            }
            else{
                end--;
            }

        }
        return false;
    }
};
