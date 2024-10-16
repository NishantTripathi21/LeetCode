class Solution {
public:
    bool check(vector<vector<char>>&board,char ch,int row,int col){
        for(int i=0;i<9;i++){
            if(board[i][col]==ch){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[row][i]==ch){
                return false;
            }
        }
        int startCol=col- col % 3;
        int startRow=row - row%3;
        for(int i=startRow;i<startRow+3;i++){
            for(int j=startCol;j<startCol+3;j++){
                if(board[i][j] ==ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch=board[i][j];
                if(ch != '.'){
                    board[i][j]='.';
                    if(!check(board,ch,i,j)){
                        return false;
                    }
                    board[i][j]=ch;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValid(board);
    }
};
