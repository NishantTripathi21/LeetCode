class Solution {
public:
//method 1-
    int duplicateM1(vector<int>&nums){
        int b=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                b= nums[i];
                break;
            }
        }
    return b;
    }
    // negative marking method . it has lower time complexity
    //we will mark nums[num[i]] visited by marking it negative and if number comes out to be negative , that is duplicate number.
    int NegativeMarkingMethod(vector<int>&nums){
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i]);
            //already visited
            if(nums[index]<0){
                ans= index;
                break;
            }
            //marking visited
            else{
                nums[index]*=-1;
            }
        }
        return ans;
    }
    int findDuplicate(vector<int>& nums) {
      int ans= NegativeMarkingMethod(nums);
      return ans;
    }
};
