class Solution {
public:
    int minOperations(vector<int>& nums) {
        int val = nums[0];
        for(int i= 0; i< nums.size(); i++) {
            if( nums[i] != val) {
                return 1;
            }
        }
        return 0;
    }
};
