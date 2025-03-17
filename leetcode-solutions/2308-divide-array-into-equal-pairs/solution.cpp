class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // int n = nums.size();
        // for(int i= 0; i< n; i++) {
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp) {
        //     if(it.second & 1)return false;
        // }
        // return true;
        sort(nums.begin(),nums.end());
        int count = 0;
        int num = -1;
        for(int i= 0; i< nums.size(); i++) {
            if(nums[i] != num) {
                num = nums[i];
                if( count & 1)return false;
                count = 1;
            }
            else {
                count++;
            }
        }
        return true;
    }
};
