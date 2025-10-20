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
    int maxFreq = 0;        
    int currFreq = 0;       
    TreeNode* prev = nullptr; 
    vector<int> modes;      

    void inorder(TreeNode* root) {
        if(!root) return;

        inorder(root->left);

        
        if(prev && prev->val == root->val) currFreq++;
        else currFreq = 1;

      
        if(currFreq > maxFreq) {
            maxFreq = currFreq;
            modes.clear();
            modes.push_back(root->val);
        } 
        else if(currFreq == maxFreq) {
            modes.push_back(root->val);
        }

        prev = root; 
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};

