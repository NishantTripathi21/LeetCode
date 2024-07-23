class Solution {
public:
    int binarySearch(vector<int>& nums,int target,int start, int end){
        int  mid=start+  (end-start)/2;
        while(start<=end){
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target){
                start=mid+1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
             mid=start+  (end-start)/2;

        }
        return -1;
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
    int search(vector<int>& nums, int target) {
        int maxIndex=maxElement(nums);
        int ans=-1;
       
        if(target>=nums[0]&& target<=nums[maxIndex]){
            ans=binarySearch(nums,target,0,maxIndex);}
         else{
            ans=binarySearch(nums,target,maxIndex+1,nums.size()-1);

        }
        return ans;
        
    }
};
