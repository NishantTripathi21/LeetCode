class Solution {
public:
    vector<int> bruteforce(vector<int>&nums){
        int size=nums.size();
        int ones=0;
        int twos=0;
        int threes=0;
        for(int i=0;i<size;i++){
            if(nums[i]==0){
                ones++;
            }
           else if(nums[i]==1){
                twos++;
            }
           else if(nums[i]==2){
                threes++;
            }
        }
        int n=0;
        while(ones--){
            nums[n]=0;
            n++;
        }
         while(twos--){
            nums[n]=1;
            n++;
        }
         while(threes--){
            nums[n]=2;
            n++;
        }
          return nums;  
            }
 
    vector<int> threePointerApproach(vector<int>&nums){
        int mid,low,high;
        mid=low=0;
        high=nums.size()-1;
        while(high>=mid){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        return nums;
         }

    vector<int>swappingapproach(vector<int>&nums){
        int index,low,high;
        index=0;low=0;
        high=nums.size()-1;
        while(index<=high){
            if(nums[index]==0){
                swap(nums[index],nums[low]);
                low++;
                index++;
            }
            else if(nums[index]==2){
                swap(nums[index],nums[high]);
                high--;
             }
             else{
                index++;
             }
        }
        return nums;
    }

    void sortColors(vector<int>& nums) {
      // bruteforce(nums);
      //  threePointerApproach(nums);
      swappingapproach(nums);
    }
};
