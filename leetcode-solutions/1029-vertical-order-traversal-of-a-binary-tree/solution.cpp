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
    map<int,vector<pair<int,int>>>mapping;
    void helper(TreeNode* root, int row,int col){
        if(!root)return;             
        mapping[col].push_back({root->val,row});
        helper(root->left,row+1,col-1);
        helper(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        helper(root,0,0);
        for (auto &col : mapping){
        auto &nodes = col.second;
        sort(nodes.begin(), nodes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second == b.second) return a.first < b.first; // Sort by value if rows are the same
            return a.second < b.second; // Otherwise, sort by row
        });
        vector<int> sorted;
        for (auto &node : nodes) {
            sorted.push_back(node.first);
        }
        ans.push_back(sorted);
    }
        return ans;
    }
};
