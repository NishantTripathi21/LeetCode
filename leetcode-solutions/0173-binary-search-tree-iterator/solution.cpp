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
class BSTIterator {
public:
    vector<int> ans;
    int index = -1;
    void inOrder(TreeNode* root , vector<int>& ans) {
        if(!root) return;
        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right , ans);
    }
    BSTIterator(TreeNode* root) {
        inOrder( root , ans);
    }
    
    int next() {
        index++;
        return ans[index];
    }
    
    bool hasNext() {
        if(index == -1 || index < ans.size()-1)return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
