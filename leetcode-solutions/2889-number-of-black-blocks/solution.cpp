class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long > ans(5,0);
        
        map<pair<int,int>,int>mp; //(i,j)-> count

        for(auto it: coordinates) {
            int x = it[0];
            int y = it[1];
            for(int i= -1; i<= 0; i++) {
                for(int j = -1; j<= 0; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if( nx >= 0 && ny >= 0 && nx < m-1 && ny < n-1 )mp[{nx,ny}]++;
                }
            }
        }

        for(auto it: mp) {
            ans[it.second]++;
        } 
        long long total = 1LL * (m - 1) * (n - 1);
        ans[0] = total - ans[1] - ans[2] - ans[3] - ans[4];        
        return ans;
    }
};
