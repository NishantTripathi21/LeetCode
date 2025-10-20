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
    TreeNode* solve(vector<int>& nums, int l, int r) {
        if(l > r)return NULL;

        int mxI = l;
        for(int i= i= l+1; i<= r; i++) {
            if(nums[i] > nums[mxI]) {
                mxI = i;
            }
        }
        TreeNode* root = new TreeNode(nums[mxI]);

        root->left = solve(nums,l,mxI-1);
        root->right = solve(nums,mxI+1,r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
