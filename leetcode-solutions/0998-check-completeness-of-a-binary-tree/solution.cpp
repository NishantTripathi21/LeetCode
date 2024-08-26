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
    bool isCompleteTree(TreeNode* root) {
        //if a null node is encountered before a valid node, it is not a complete BT
        queue<TreeNode*>q;
        q.push(root);
        bool nullFound=false;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            if(!temp){
                nullFound=true;
            }
            else{
                if(nullFound){
                    return false;
                }
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};
