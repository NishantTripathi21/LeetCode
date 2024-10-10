class Solution {
public:
    int pivotElement(vector<int>&nums){
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return nums[low];

    }
    int maxElement(vector<int>&nums){
        int start=0;
        int end=nums.size()-1;
        int  mid=start+  (end-start)/2;
        while(start<end){
            if(start==end) return start;
            else if(mid+1<nums.size() &&  nums[mid]>nums[mid+1]) return mid;
            else if(mid-1 >=0 && nums[mid]<nums[mid-1]){
                return mid-1;
            }
            else if(nums[start]>nums[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+ (end-start)/2;
        }
        return start;
    }
    int findMin(vector<int>& nums) {
        if(nums[0] <= nums[nums.size()-1])return nums[0];
        return nums[maxElement(nums)+1 % nums.size()];
    }
};
