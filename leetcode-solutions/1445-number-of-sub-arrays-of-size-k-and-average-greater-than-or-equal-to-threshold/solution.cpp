class Solution {
public:
    int implement( vector<int>& arr, int k, int threshold ){
        int left = 0;
        int right = 0;
        int avg = 0;
        int sum = 0;
        int count = 0;
        while( right < arr.size()){
            sum += arr[right];
            if( right - left + 1 >= k){
                avg = sum/k;
                if( avg >= threshold){
                    count++;
                }
                sum -= arr[left];
                left++;
            }
            right++;
        }
        return count;
    }
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        return implement( arr, k ,threshold);
    }
};
