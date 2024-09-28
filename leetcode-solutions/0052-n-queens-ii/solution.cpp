class Solution {
public:
    bool isSafe(vector<vector<int>>&matrix,int row,int col){
        for(int i=col;i>=0;i--){
            if(matrix[row][i]==1)return false;
        }
        for(int i=row;i>=0;i--){
            if(matrix[i][col]==1)return false;
        }
        int i=row;int j=col;
        while(i >= 0 && j >= 0 ){
            if(matrix[i][j] ==1)return false;
            i--;j--;
        }
        int k=row;int l=col;
        while(  k < matrix.size() && l >= 0){
            if(matrix[k][l] ==1)return false;
            k++;
            l--;
        }
        return true;
    }
    void usingRec(vector<vector<int>>&matrix,int col,int &ans){
        if(col==matrix.size()){
            ans+=1;
            return;
        }
        for(int row=0;row<matrix.size();row++){
            if(isSafe(matrix,row,col)){
                matrix[row][col]=1;
                usingRec(matrix,col+1,ans);
                matrix[row][col]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int ans=0;
        usingRec(matrix,0,ans);
        return ans;
    }
};
