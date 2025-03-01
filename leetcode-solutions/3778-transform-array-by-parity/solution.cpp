class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int index=  0;
        while(index<nums.size()) {
            if(nums[index]&1){
                nums[index] = 1;
            }
            else{
                nums[index] = 0;
            }
            index++;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};
