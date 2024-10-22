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
    vector<TreeNode*>ans;
    unordered_map<string,int>encoding;
    string encode(TreeNode*root){
        if(!root)return "N";
        string curr=to_string(root->val);
        string left=encode(root->left);
        string right=encode(root->right);
        string s= curr + "," + left + ","+right;
        if(encoding.find(s) != encoding.end()){
            if(encoding[s] ==1){
                ans.push_back(root);
            }
            encoding[s]++;
        }
        else{
            encoding[s]=1;
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        cout<<encode(root);
        return ans;
    }
};
