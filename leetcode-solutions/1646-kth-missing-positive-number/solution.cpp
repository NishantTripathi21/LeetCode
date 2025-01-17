class Solution {
public:
    int method1( vector<int>& arr, int k){
        //int ans = 0;
        for( int i: arr){
            if( i <= k)k++;
            else{
                break;
            }
        }
        return k;
    }
    int method2( vector<int>& nums, int k){
        // binary search
        int low = 0;
        int high = nums.size()-1;
        while( low <= high){
            int mid = (low+high) / 2;
            if( nums[mid] - (mid+1) >= k ){
                //cout<<" missing: "<< nums[mid] - mid+1<<" ";
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            //cout<<" high: "<<high<<" low: "<<low<<" mid: "<<mid<<endl;
        }
        return k+high+1;
    }
    int findKthPositive(vector<int>& arr, int k) {
        return method2(arr,k);
    }
};
