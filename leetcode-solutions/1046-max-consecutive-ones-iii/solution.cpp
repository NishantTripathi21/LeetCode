class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0;
        int left=0;
        int right=0;
        int zeros=0;
        while(right < nums.size()){
            if(nums[right]==0){
                zeros++;
            }
            while(zeros > k){
                if(nums[left]==0){
                    zeros--;
                }
                left++;
            }
            maxLen=max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};
