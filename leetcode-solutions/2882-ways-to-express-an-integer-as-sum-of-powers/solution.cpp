class Solution {
public:
    int mod = 1e9+7;
    int func(int n, int sum, int x, int num,vector<vector<int>>& memo){
        if(sum == n){return 1;}
        int tmp = pow(num, x);

        if(sum + tmp > n){return 0;}
        if(memo[sum][num] != -1){
            return memo[sum][num];
        }
        int take = func(n, sum + tmp, x, num+1,memo);
        int notTake = func(n, sum, x, num+1,memo);

        return memo[sum][num]= (take+notTake) % mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>>memo(301,vector<int>(301,-1));
        return func(n, 0, x, 1,memo) % mod;
    }
};
