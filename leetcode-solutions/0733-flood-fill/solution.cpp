class Solution {
public:
    void dfs( int sr, int sc, vector<vector<int>>& ans, int initialColor,int color, vector<vector<int>>& image){
        int m = ans.size();
        int n = ans[0].size();
        ans[sr][sc] = color;
        vector<pair<int,int>> delta = {{-1,0},{0,1},{1,0},{0,-1}};

        for(auto [dx,dy]: delta) {
            int newX = sr + dx;
            int newY = sc + dy;
            if( newX >= 0 && newX < m && newY >= 0 && newY < n && image[newX][newY] == initialColor && ans[newX][newY] == initialColor) {
                dfs(newX,newY,ans,initialColor,color,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor == color) return image;
        vector<vector<int>>ans = image; 
        dfs(sr,sc,ans, initialColor, color,image);
        return ans;
    }
};
