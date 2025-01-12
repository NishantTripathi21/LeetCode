class Solution {
public:
    int method( vector<int>& customers, vector<int>& grumpy, int minutes ){
        int maxi1 = 0;
        int left = 0;
        int right = 0;
        int sum = 0;
        while( right < customers.size()){
            if( grumpy[right] == 1){
                sum += customers[right];
            }
            while( right - left + 1 >= minutes){
                maxi1 = max( maxi1,sum);
                if( grumpy[left] == 1){
                    sum -= customers[left];
                }
                left++;
            }
            right++;
        }
        right = 0;
        sum = 0;
        while( right < customers.size()){
            if( grumpy[right] == 0){
                sum += customers[right];
            }
            right++;
        }
        return sum + maxi1;
    }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        return method( customers,grumpy,minutes);
    }
};
