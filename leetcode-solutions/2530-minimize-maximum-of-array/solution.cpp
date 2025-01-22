class Solution {
public:
    bool possible(vector<int> &nums, int mid_max) {
        int n = nums.size();
        vector<long long> arr(begin(nums), end(nums));
        for(int i = 0; i<n-1; i++) {
            if(arr[i] > mid_max)
                return false;
            long long buffer = mid_max - arr[i];
            arr[i+1] = arr[i+1] - buffer;   
        }
        return arr[n-1] <= mid_max;
        
    }
    long long method( vector<int>& nums) {
        long long low = 0;
        long long high = *max_element(nums.begin(),nums.end());
        long long result = high;
        while( low <= high){
            long long mid = (low+high)/2;
            //cout<<" mid: "<<mid<<" possible: "<<possible(nums,mid)<<endl;
            if( possible(nums,mid)){
                high = mid-1;
                result = mid;
            }
            else{
                low = mid+1;
            } 
        }
        return result;
    }
    long long minimizeArrayValue(vector<int>& nums) {
        return method( nums);
    }
};
