class Solution {
public:
    vector<int> method1(vector<int>&nums){
        // tc= N;
        // sc= N;
        int neg = 1;
        vector<int>ans(nums.size(),0);
        int pos = 0;
        int index = 0;
        while( index < nums.size()){
            if( nums[index] < 0){
                ans[neg] = nums[index];
                neg = neg + 2;
            }
            else if( nums[index] >= 0){
                ans[pos] = nums[index];
                pos++;
                pos++;
            }
            index++;
        }
        return ans;
    }
    vector<int> method2 (vector<int>& nums){
        // tc= 2N;
        // sc= N;
        int size = nums.size();
        vector<int>pos;
        vector<int>neg;
        int index = 0;
        while(index < nums.size()){
            if( nums[index] < 0){
                neg.push_back(nums[index]);
            }
            else{
                pos.push_back(nums[index]);
            }
            index++;
        }
        
        for( int i=0; i < size / 2; i++){
            nums[2*i] = pos[i];
            nums[2*i + 1] = neg[i];
        }
        return nums;

    }
    vector<int> rearrangeArray(vector<int>& nums) {
        return method2(nums);
    }
};
