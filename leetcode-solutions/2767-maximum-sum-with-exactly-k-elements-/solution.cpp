class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort( nums.begin(),nums.end());
        int element= nums[nums.size()-1];
        int ans=0;
        while( k ){
            ans= ans+ element;
            element++;
            k--;
        }
        return ans;
    }
};
