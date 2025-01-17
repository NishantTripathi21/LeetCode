class Solution {
public:
    int method2( vector<int>& nums){
        sort( nums.begin(),nums.end());
        int n = nums.size();
        int low = 0;
        int high = n;
        while( low <= high){
            int mid = (low + high)/2;
            int lb = lower_bound( nums.begin(),nums.end(), mid) - nums.begin();
            //cout<<" lb "<<lb<<endl;
            if( n - lb == mid)return mid;
            else if( n - lb > mid)low = mid+1;
            else high = mid -1;
        }
        return -1;
    }
    int method1( vector<int>& nums){
        int n = nums.size();
        for( int i = 0; i <= n; i++) {
            int count = 0;
            for( int j : nums){
                if( j >= i){
                    count++;
                }
            }
            if( count == i)return i;
        }
        return -1;
    }
    int specialArray(vector<int>& nums) {
        return method2(nums);
    }
};
