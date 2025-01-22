class Solution {
public:
    typedef long long ll;
    
    bool possible(vector<int>& batteries, ll mid_time, int n) {
        ll target = n*mid_time; //each computer will run mid_time minutes
        ll sum = 0;
        for(int i = 0; i<batteries.size(); i++) {
            target -= min((ll)batteries[i], mid_time);
            if(target <= 0)
                return true;
        }
        return target <= 0;
    }
    long long method( int n, vector<int>& batteries) {
        long long low= 1;
        long long sum_total_minutes = 0;
        for(auto &mints : batteries){
            sum_total_minutes += mints;
        }
        ll high = sum_total_minutes/n;
        long long ans = 0;
        while( low <= high){
            long long mid = (low + high)/2;
            if(possible(batteries,mid,n)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        return method(n,batteries);
    }
};
