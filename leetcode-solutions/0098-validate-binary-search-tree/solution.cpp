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
    bool helper(TreeNode*root,long long int upperBound,long long int lowerBound){
        if(!root){
            return true;
        }
        bool cond1=root->val > lowerBound;
        bool cond2=root->val < upperBound;
        bool leftAns=helper(root->left,root->val,lowerBound);
        bool rightAns=helper(root->right,upperBound,root->val);
        return cond1 && cond2 && leftAns && rightAns;
    }
    bool isValidBST(TreeNode* root) {
        long long int lowerBound=-2147498664;
        long long int upperBound=2147483947;
        return helper(root,upperBound,lowerBound);

    }
};
