class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int a = 1;
        int b = 0; 
        while(b < nums.size() && nums[b] != 0){
            b++;
        }
        if(b==nums.size()-1)return;
        a = b + 1;
        while( a < nums.size()){
            if( nums[a] != 0){
                swap(nums[a],nums[b]);
                b++;
            }
            a++;
        }
    }
};
