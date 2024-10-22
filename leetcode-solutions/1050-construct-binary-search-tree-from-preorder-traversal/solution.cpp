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
    // TreeNode* InorderToBst(vector<int>&inorder,int start,int end){
    //     if(start > end)return nullptr;
    //     int mid=(start+end)/2 ;
    //     int element=inorder[mid];
    //     auto root=new TreeNode(element);
    //     root->left=InorderToBst(inorder,start,mid-1);;
    //     root->right=InorderToBst(inorder,mid+1,end);;
    //     return root;
    // }
    TreeNode* linkTree(TreeNode* root,int data){
        if(!root){
            root=new TreeNode(data);
            return root;
        }
        if(data > root->val){
            root->right=linkTree(root->right,data);
        }
        else{
            root->left=linkTree(root->left,data);
        }
        return root;
    }
    TreeNode*createBTS(vector<int>&preorder){
        TreeNode*root=NULL;
        int n=0;
        while(n < preorder.size()){
            root=linkTree(root,preorder[n]);
            n++;
        }
        return root;
        cout<<"operation succefull"<<endl;
    }
    TreeNode* build(int& i,int min,int max,vector<int>&preorder){
        if(i>=preorder.size()){
            return 0;
        }
        TreeNode*root=0;
        if(preorder[i] > min && preorder[i] < max){
            root=new TreeNode(preorder[i++]);
            root->left=build(i,min,root->val,preorder);
            root->right=build(i,root->val,max,preorder);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // sort(preorder.begin(),preorder.end());
        // for(auto i:preorder)cout<<i<<" ";
        // return InorderToBst(preorder,0,preorder.size()-1); 
       // return createBTS(preorder);
       int i=0;
       return build(i,INT_MIN,INT_MAX,preorder);
    }
};
