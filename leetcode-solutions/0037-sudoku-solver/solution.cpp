class Solution {
public:
    bool isPossible(vector<vector<char>>&board,int x,int y,char ch){
        for(int i=0;i<9;i++){
            if(board[i][y]==ch){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[x][i]==ch){
                return false;
            }
        }
        //checking3*3
        int startCol=y- y % 3;
        int startRow=x - x%3;
        for(int row=startRow;row<startRow+3;row++){
            for(int col=startCol;col<startCol+3;col++){
                if(board[row][col] ==ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool usingRec(vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isPossible(board,i,j,ch)){
                            board[i][j]=ch;
                            if(usingRec(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool solve= usingRec(board);
    }
};
