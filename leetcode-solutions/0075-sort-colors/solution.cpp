class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i= 0;
        int j = nums.size()-1;
        int index= 0;
        while( i < nums.size() && nums[i]==0) {
            i++;
        }
        index = i ;
        while(index < nums.size() && i < j) {
            if(nums[index] == 0) {
                swap(nums[index],nums[i]);
                i++;
                index++;
            }
            else if(nums[index] == 2 && index < j) {
                swap(nums[index],nums[j]);
                j--;
            }
            else index++;
        } 
    }
}; 
