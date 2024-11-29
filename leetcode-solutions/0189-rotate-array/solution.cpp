class Solution {
public:
    // void print(vector<int> nums){
    //     for(auto i:nums){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    void opt(vector<int>& nums, int k){
        k = k % nums.size();
        // reverse whole array
        reverse(nums.begin(), nums.end());
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());  
    }
    void rotate(vector<int>& nums, int k) {
        // vector<int>ans(nums.size());
        // k = k% nums.size();
        // for(int i=0;i<nums.size();i++){
        //     int newIndex=(i+k)%nums.size();
        //     ans[newIndex]=nums[i];
        // }
        // nums=ans;
        opt(nums,k);
        
    }
};
