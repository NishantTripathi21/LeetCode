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
    bool helper(TreeNode* p, TreeNode*q){
        if(!p && !q){
            return true;
        }
        if(!p && q)return false;
        if( p && !q)return false;

        bool currAns= p->val == q->val;
        if(!currAns)return false;
        return currAns && helper(p->left,q->left) && helper(p->right , q-> right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
         return helper(p,q);
    }
};
