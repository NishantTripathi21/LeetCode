class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        int index = 0;
        while( index < nums.size()){
            if(count == 0){
                candidate = nums[index];
                count++;
                index++;
            }
            else{
                if(nums[index] == candidate){
                    count++;
                }
                else{
                    count--;
                }
                index++;
            }
        }
        return candidate;
    }
};
