class Solution {
public:
    int method1( vector<int>& nums) {
        static constexpr int mod = 1000000007; 
        sort( nums.begin(), nums.end());
        long long sum = 0;
        long long internal = 0;
        for ( int i= nums.size()-2; i >= 0; i-- ){
            internal = ((nums[i+1] * (long long)nums[i+1]) % mod + (internal * 2) % mod) % mod;
            sum = (sum + (nums[i] * internal) % mod) % mod;
        }
        for( int i: nums){
            sum = (sum + ((long long)i * i % mod * i % mod) % mod) % mod;
        }
        return sum % mod;
    }
    int sumOfPower(vector<int>& nums) {
        return method1(nums);
    }
};
