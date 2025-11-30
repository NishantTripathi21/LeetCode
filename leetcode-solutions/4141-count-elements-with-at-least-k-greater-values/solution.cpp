class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;
        for(int i= 0; i< n; i++) {
            int val = nums[i];
            int nv = val + 1;
            int idx = lower_bound(nums.begin(), nums.end(), nv) - nums.begin();
            if(n - idx >= k){
                count++;
            }
        }
        return count;
    }
};
