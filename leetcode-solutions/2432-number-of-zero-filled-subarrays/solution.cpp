class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int zeros = 0;
        long long subArrays = 0;
        for(int i = 0; i< nums.size(); i++) {
            if(nums[i] == 0) {
                zeros++;
            }
            else {
                subArrays += (long long)((long long)zeros*(zeros+1))/2;
                zeros = 0;
            }
        }
        subArrays += (long long)((long long)zeros*(zeros+1))/2;
        return subArrays;
    }
};
