class Solution {
public:
    int method( vector<int>& nums){
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        int s = 1;
        int e = nums.size()-2;
        while( s<=e){
            if( s == e)return nums[s];
            int mid = s + (e-s)/2;
            if( nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                //eliminate the left half:
                s = mid + 1;
            }
            else {
                //eliminate the right half:
                e = mid - 1;
            }

        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     ans=ans^nums[i];

        // }
        
        return method(nums);
        
    }
};
