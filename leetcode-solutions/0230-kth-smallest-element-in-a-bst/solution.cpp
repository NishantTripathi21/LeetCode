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
    int kthSmallest(TreeNode* root, int &k) {
        if(!root)return -1;
        //we'll do LNR traversal and reduce k value each time we hit N
        //logic- while we go left,we gets smaller and smaller value,when we return for right via N, we start getting 
        //bigger number 
        //this can be understood as -in LNR traversal in bts, we get sorted array.
        //lefft traversal
        int leftSide=kthSmallest(root->left,k);
        if(leftSide!=-1)return leftSide;
        //Node
        k--;
        if(!k)return root->val;
        //right traversal
        int rightSide=kthSmallest(root->right,k);
        return rightSide;
    }
};
