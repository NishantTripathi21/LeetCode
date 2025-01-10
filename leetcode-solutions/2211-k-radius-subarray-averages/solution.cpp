class Solution {
public:
    vector<int> implement( vector<int>& nums, int k){
        vector<int>avgs( nums.size(), -1);
        if( nums.size() < (2*k + 1))return avgs;
        int left = 0;
        int right = 0;
        long long sum = 0;
        while( right < nums.size()){
            sum += nums[right];
            int center = (right + left)/2;
            if( (right - left + 1) >= 2*k +1 && center >= k && center < nums.size() - k ){
                long long avg = (long long)( sum ) / (2*k +1);
                avgs[center] = avg;
                sum -= nums[left++];
            }
            right++;
        }
        return avgs;

    }
    vector<int> getAverages(vector<int>& nums, int k) {
        return implement(nums,k);
    }
};
