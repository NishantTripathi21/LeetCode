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
    void inorderBuild(TreeNode*root,vector<int>&inorder){
        if(!root)return;
        inorderBuild(root->left,inorder);
        inorder.push_back(root->val);
        inorderBuild(root->right,inorder);
    }
    TreeNode* build(vector<int>&inorder,int start,int end){
        if(start > end)return nullptr;
        int mid=(start+end)/2;
        auto leftRoot=build(inorder,start,mid-1);
        auto rightRoot=build(inorder,mid+1,end);
        int element=inorder[mid];
        TreeNode* root=new TreeNode(element);
        root->left=leftRoot;
        root->right=rightRoot;
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        //we can use BST from inorder code for this question
        vector<int>inorder;
        inorderBuild(root,inorder);
        for(auto i:inorder)cout<<i<<" ";
        //create BST using inorder
        return build(inorder,0,inorder.size()-1);
    }
};
