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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        vector<double>ans;
        q.push(root);
        double sum = 0;
        int count = 0;
        while(!q.empty()) {
            int n = q.size();
            for(int i= 0; i< n; i++) {
                auto it= q.front();
                q.pop();
                count++;
                sum += it->val;
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            double avg = (double)sum/(double)count;
            ans.push_back(avg);
            sum = 0;
            count = 0;
            
        }
        return ans;
    }
};
