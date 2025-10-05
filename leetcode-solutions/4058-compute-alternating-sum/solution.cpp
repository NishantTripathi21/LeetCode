class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int index = 0;
        bool flag = true;
        int sum = 0;
        while(index < nums.size()) {
            if(flag) {
                sum += nums[index];
            }
            else {
                sum -= nums[index];
            }
            index++;
            flag = !flag;
        }
        return sum;
    }
};
