class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int index = 2;
        int count = 2;
        int maxAns = 2;
        while( index < nums.size()) {
            if(nums[index] == nums[index-1] + nums[index-2]) {
                count += 1;
                maxAns = max(count,maxAns);
            }
            else{
                count = 2;
            }
            index++;
        }
        return maxAns;
    }
};
