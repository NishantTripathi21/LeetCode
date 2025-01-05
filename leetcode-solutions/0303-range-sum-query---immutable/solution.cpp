class NumArray {
public:
    unordered_map<int,int>mp;
    NumArray(vector<int>& nums) {
        int preSum = 0;
        mp[-1] = 0;
        for( int i=0;i<nums.size();i++){
            preSum += nums[i];
            //cout<<" prefix: "<<preSum<<" index: "<<i<<endl;
            mp[i] = preSum;
        }
    }
    
    int sumRange(int left, int right) {
        return mp[right] - mp[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
