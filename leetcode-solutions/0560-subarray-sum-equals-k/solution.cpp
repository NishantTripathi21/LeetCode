class Solution {
public:
    // method1 - generate all subarrays-brute

    int method2( vector<int>& nums, int k){
        unordered_map<int,int>mp;
        mp[0] = 1;
        int preSum = 0;
        int count = 0;
        for( int i = 0 ;i < nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k;
            if( mp.find(remove) != mp.end()){
                count += mp[remove];
            }
            
            mp[preSum] += 1;
        }
        return count;
        
    }
    int subarraySum(vector<int>& nums, int k) {
        return method2(nums,k);
    }
};
