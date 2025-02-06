class Solution {
public:
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int start = 0, end = 0, lastValid = -1, count = 0;
        int n = nums.size();
        while(end < n){
            if(nums[end] > right){
                start = end + 1;
                lastValid = -1;
            }
            else{
                if(nums[end] >= left){
                    lastValid = end;
                }
                if(lastValid != -1) {
                    count += lastValid - start + 1;
                }
            }
            end++;
        }
        return count;
    }
};
