class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int s=0;
        int e=nums.size()-1;
        int m=(s+e)/2;
        while(s<=e){
            if(nums[m]==target) return m;
            else if(nums[m]<target){
                s=m+1;
            }
            else{
                e=m-1;
            }
            m=(s+e)/2;
        }
        return s;
        
    }
};
