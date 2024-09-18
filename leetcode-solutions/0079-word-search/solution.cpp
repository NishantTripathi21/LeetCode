class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int x,int y,vector<vector<int>>&mapping){
        if( x < board.size() && y < board[0].size() && !mapping[x][y]){
            return true;
        }
        return false;
    }
    void usingRec(vector<vector<char>>& board, string&word,int index,int x,int y,bool& ans,vector<vector<int>>&mapping){
        if(index== word.size() -1 && board[x][y] == word[index]){
            ans=true;
            return;
        }
        if( board[x][y] != word[index]){
            ans=false;
            return;
        }
        if(isSafe(board,x,y+1,mapping) && word[index+1] == board[x][y+1]){
            mapping[x][y+1]=1;
            usingRec(board,word,index+1,x,y+1,ans,mapping);
            mapping[x][y+1]=0;
        }
        if(isSafe(board,x+1,y,mapping) && word[index+1]==board[x+1][y]){
            mapping[x+1][y]=1;
            usingRec(board,word,index+1,x+1,y,ans,mapping);
            mapping[x+1][y]=0;
        }
        if(isSafe(board,x,y-1,mapping) && word[index+1]==board[x][y-1]){
            mapping[x][y-1]=1;
            usingRec(board,word,index+1,x,y-1,ans,mapping);
            mapping[x][y-1]=0;
        }
        if(isSafe(board,x-1,y,mapping) && word[index+1]==board[x-1][y]){
            mapping[x-1][y]=1;
            usingRec(board,word,index+1,x-1,y,ans,mapping);
            mapping[x-1][y]=0;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        vector<vector<int>>mapping(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    mapping[i][j]=1;
                    usingRec(board,word,0,i,j,ans,mapping);
                    if(ans){
                        return ans;
                        break;
                    }
                    else{
                        mapping[i][j]=0;
                    }
                }
            }
        }
        return false;
        
    }
};
