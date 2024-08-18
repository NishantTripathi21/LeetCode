/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(!root)return NULL;
        if(root==p)return p;
        if(root==q)return q;

        TreeNode*leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
        if(!leftAns && !rightAns)return NULL;
        else if(leftAns && !rightAns) return leftAns;
        else if(!leftAns && rightAns) return rightAns;
        else{
            return root;
        }
    }
};
