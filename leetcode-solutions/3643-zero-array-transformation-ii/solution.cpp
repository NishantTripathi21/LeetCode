class Solution {
public:
    bool isPossible(vector<int>& nums, vector<vector<int>>& queries, int minK) {
        vector<int>cons(nums.size()+1,0);
        for(int i= 0; i<= minK; i++) {
            auto it = queries[i];
            int start = it[0];
            int end = it[1];
            int val = it[2];
            cons[start] += val;
            cons[end+1] -= val;
        }
        int sum = 0;
        for(int i= 0; i< nums.size(); i++) {
            sum += cons[i];
            if( sum < nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0;
        int high = queries.size()-1;
        int minK = -1;
        bool flag = false;
        for(int i= 0; i< nums.size(); i++) {
            if(nums[i] > 0) flag= true;
        }
        if(!flag)return 0;
        while( low <= high) {
            int mid = low - (low - high)/2;
            if(isPossible(nums,queries,mid)) {
                minK = mid+1;
                high = mid - 1;
            }
            else{
                low =  mid + 1;
            }
        }
        return minK;
    }
};
