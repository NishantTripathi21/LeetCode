class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int median = 0;
        int n = grid.size();
        int m = grid[0].size();
        int size = n*m;
        vector<int>nums;
        for(int i= 0; i< n; i++) {
            for(int j= 0; j< m; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        median = nums[size / 2];
        int operations = 0;
        int mod = nums[0] % x;
        for(int i= 0; i< nums.size(); i++) {
            if(nums[i] % x != mod)return -1;
            operations += abs(nums[i] - median) / x;
        }
        return operations;   
    }
};
