class Solution {
public:
    vector<int> method1( vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>preSum;
        int sum= 0;
        for( int i: nums){
            sum += i;
            preSum.push_back(sum);
        }
        vector<int>ans;
        int n = queries.size();
        for( int i = 0; i< queries.size() ; i++){
            int ub = upper_bound(preSum.begin(),preSum.end(),queries[i]) - preSum.begin();
            //cout<<" lowerBound: "<<lb;
            ans.push_back( ub );
        }
        return ans;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        return method1(nums,queries);
    }
};
