class Solution {
public:
int prefixSumApproach(vector<int>&nums){
    int size=nums.size();
    vector<int>leftsum(size,0);
    vector<int>rightsum(size,0);
    //calculation of left sum array
    for(int i=1;i<size;++i){
        leftsum[i]=leftsum[i-1]+nums[i-1];
    }
    for(int i=size-2;i>=0;--i){
        rightsum[i]=rightsum[i+1]+nums[i+1];
    }
    for(int i=0;i<size;i++){
        if(leftsum[i]==rightsum[i]){
            return i;
        }
    }
    return -1;
    }
    int pivotIndex(vector<int>&nums) {
        int s=nums.size();
        return prefixSumApproach(nums);
    }
};
