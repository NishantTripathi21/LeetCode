class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadan's algo
        int maxi = 0;
        int ans = INT_MIN;
        int index = 0;
        while( index < nums.size()){
            maxi += nums[index];
            ans = max( ans, maxi);
            if(maxi < 0){
                maxi = 0;
            }
            index++;
        }
        return ans;
    }
};
