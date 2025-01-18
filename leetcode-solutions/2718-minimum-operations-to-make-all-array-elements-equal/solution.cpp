class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        if (nums.empty()) return vector<long long>(queries.size(), 0);
        vector<long long>preSum(nums.size());
        sort(nums.begin(),nums.end());
        preSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        vector<long long>ans;
        for( int i = 0; i< queries.size(); i++){
            int query = queries[i];
            int lb = lower_bound(nums.begin(),nums.end(),query) - nums.begin();
            long long leftSum = lb > 0 ? preSum[lb - 1] : 0;
            long long rightSum = preSum.back() - leftSum;

            long long leftOperations = (long long)query * lb - leftSum;
            long long rightOperations = rightSum - (long long)query * (nums.size() - lb);
            long long total = (long long) leftOperations + (long long)rightOperations;
            ans.push_back( total );
        }
        return ans;
    }
};
