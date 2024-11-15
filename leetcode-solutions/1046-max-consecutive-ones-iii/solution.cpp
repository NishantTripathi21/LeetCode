class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int left=0;
        int right=0;
        int zeros=0;
        int ones=0;
        while(right < nums.size()){
            if(nums[right] == 0){
                zeros++;
            }
            while( zeros > k && left <= right){
                if(nums[left] == 0){
                    zeros--;
                }
                left++;
            }
            ans=max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
