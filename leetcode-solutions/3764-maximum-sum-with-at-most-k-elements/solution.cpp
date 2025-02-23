class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<int,int>>maxHeap; //{value,row}
        int n = grid.size();
        int m = grid[0].size();
        for( int i = 0; i< n; i++) {
            for( int j = 0; j< m; j++) {
                maxHeap.push({grid[i][j],i});
            }
        }
        long long ans = 0;
        while(k) {
            auto [value,row] = maxHeap.top();
            maxHeap.pop();
            if(limits[row] > 0){
                limits[row]--;
                k--;
                ans= (long long)ans+ value;
            }
        }
        return ans;
    }
};
