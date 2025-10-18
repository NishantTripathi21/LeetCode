class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int index = 0;
        int prev = INT_MIN;
        int count = 0;
        while(index < nums.size()) {
            int num = nums[index];
            int cur = min(max(num-k,prev+1),num+k);
            if(cur > prev) {
                count++;
                prev = cur;
            }
            index++;
        }
        return count;
    }
};
