class Solution {
public:
     vector<int> TwoPtrApproach(vector<int>nums,int k,int x){
        int i=0;int j=nums.size()-1;
        while(j-i>=k){
            if(x-nums[i]>nums[j]-x){
                i++;
            }
            else{
                j--;
            }
        }
        vector<int>ans;
        for(int b=i;b<=j;b++){
            ans.push_back(nums[b]);
        }
        return ans;
     }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return TwoPtrApproach(arr,k,x);
    }
};
