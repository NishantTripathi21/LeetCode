class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1;
        int high = n;
        while( low <= high){
            int mid = low + (high - low)/2;
            long long sum = mid * (double)(mid+1)/2.0;
            if( sum > n){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return high;
    }
};
