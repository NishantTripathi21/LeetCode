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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preIndex,int size,int InorderStart,int InorderEnd,unordered_map<int, int>& inorderMap){
        if(preIndex>=size || InorderStart >InorderEnd)return NULL;
        int element=preorder[preIndex];
        preIndex++;
        TreeNode* root=new TreeNode(element);
        int positionInInorder=inorderMap[element];
        root->left=solve(preorder,inorder,preIndex,size,InorderStart,positionInInorder-1,inorderMap);
        root->right=solve(preorder,inorder,preIndex,size,positionInInorder+1,InorderEnd,inorderMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) return NULL;
        unordered_map<int, int> inorderMap;
        for(int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        int preIndex = 0;
        return solve(preorder, inorder, preIndex, preorder.size(), 0, inorder.size() - 1,inorderMap);
        
    }
};
