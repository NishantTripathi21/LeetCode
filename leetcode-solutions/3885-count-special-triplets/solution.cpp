class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>left,right;
        for(int i= 2; i< nums.size(); i++) {
            right[nums[i]]++;
        }
        left[nums[0]]++;
        int mod = 1e9 + 7;
        long long ans = 0;
        for(int j= 1; j< nums.size()-1; j++) {
            int v = nums[j];
            int ic = left[nums[j]*2];
            int rc = right[nums[j]*2];
            ans = (ans + ((1LL*ic * rc))%mod)%mod;
            ans %= mod;
            right[nums[j+1]]--;
            left[nums[j]]++;
        }
        return ans;
    }
};
