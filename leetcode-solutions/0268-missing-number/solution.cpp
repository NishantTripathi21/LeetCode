class Solution {
public:
    int missingNumberUsingOtherArray(vector<int>&nums){
         int missing;
        // sort the array
        // make a new array with all elements upto n
        // compare both arrays with corner case like exaple two
        sort(nums.begin(), nums.end()); 
        vector<int>brr(nums.size()+1,0);
        for(int i=0;i<=nums.size();i++){
            brr[i]=i;
        }
        if(nums.back()!=brr.back()){
             missing= brr.back();
         }
         else{
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=brr[i]){
                missing = brr[i];
                break;
            }
         }
         }
    return missing;
    }

    int MissingElementUsingXor(vector<int>&nums){
        int ans=0;
        //Xor all elements of Array
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
        }
        //xor all range items from [0,N]
        for(int i=0;i<=nums.size();i++){
            ans^=i;
        }
        return ans;
    }


    int missingNumber(vector<int>& nums){
      return  MissingElementUsingXor(nums);
           } 
};
