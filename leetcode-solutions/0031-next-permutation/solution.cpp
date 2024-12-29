class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find break point
        int size = nums.size()-1;
        int breakPoint = -1;
        for( int i=size-1; i>=0;i--){
            if( nums[i] < nums[i+1]){
                breakPoint = i;
                break;
            }
        }
        if( breakPoint == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        else{
            //find smallest number just greater than breakpoint number
            for( int i = size;i>=0;i--){
                //cout<<"i "<<i<<"breakPoint "<<breakPoint<<endl;
                if( nums[breakPoint] < nums[i]){
                    //cout<<"swapping"<<endl;
                    // number found, now swap and break the loop
                    swap(nums[breakPoint],nums[i]);
                    break;
                }
            }
            // reverse the array from breakPoint+1 to size
            reverse(nums.begin()+breakPoint+1, nums.end());
            return;
        }
    }
};
