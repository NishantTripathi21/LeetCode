class Solution {
public:
    // method1 - generate all subarrays-brute

    int method2( vector<int>& nums, int k){
        unordered_map<int,int>mp;
        mp[0] = 1;
        int sum = 0,count= 0 ;
        for(int i= 0; i< nums.size(); i++) {
            sum += nums[i];
            int req = sum - k;
            if(mp.find(req) != mp.end()) {
                count += mp[req];
            }
            mp[sum]++;
        }
        return count;
        
    }
    int subarraySum(vector<int>& nums, int k) {
        return method2(nums,k);
    }
};
