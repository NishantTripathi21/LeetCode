class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int a = 1;
        // int b = 0; 
        // while(b < nums.size() && nums[b] != 0){
        //     b++;
        // }
        // if(b==nums.size()-1)return;
        // a = b + 1;
        // while( a < nums.size()){
        //     if( nums[a] != 0){
        //         swap(nums[a],nums[b]);
        //         b++;
        //     }
        //     a++;
        // }
        int i = 0;
        int j = 0;
        while( i < nums.size() && nums[i] != 0) {
            i++;
        }
        if(i == nums.size()-1)return;
        j = i + 1;
        while(j < nums.size()) {
            if(nums[j] != 0) {
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
        return;
    }
    
    

};
