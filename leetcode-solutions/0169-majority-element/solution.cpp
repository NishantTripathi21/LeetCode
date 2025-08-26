class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candi = nums[0];
        int occurance= 1;
        for(int i= 1; i< nums.size(); i++) {
            if(occurance == 0) {
                candi = nums[i];
            }
            if(nums[i]== candi) {
                occurance++;
            }
            else {
                occurance--;
            }
        }
        return candi;
    }
};
