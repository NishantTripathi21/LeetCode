class Solution {
public:
    set<pair<int,int>> method1(vector<int>&nums , int k){
         sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        int i=0;int j=1;
       // int ans=0;
        while(j<nums.size()){
            int diff=nums[j]-nums[i];
            if(diff==k){
                ans.insert({nums[i],nums[j]});
                i++;j++;
            }
            else if(diff>k){
                i++;
            }
            else{
                j++;
            }
            if(i==j){
                j++;
            }
        }
        return ans ;
    }

// method two using binary search 
int binarysearch(vector<int>nums,int start, int t){
    int end=nums.size()-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(nums[mid]==t){
            return mid;
        }
        else if(nums[mid]<t){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;
}

    int findPairs(vector<int>& nums, int k) {
         //  return method1(nums,k).size();
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            if(binarysearch(nums,i+1,nums[i]+k) !=-1){
                ans.insert({nums[i],nums[i]+k});
            }
        }
        return ans.size();
        
    }
};
