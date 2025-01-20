class Solution {
public:
    double findTime( vector<int>&dist, int speed) {
        double time = 0.0;
        for(int i= 0; i< dist.size(); i++) {
            double timeForSegment = (double)(dist[i]) / speed;
            if (i < dist.size() - 1) {
                time += ceil(timeForSegment);
            }
            else {
                time += timeForSegment;
            }
        }
        return time;
    }
    int method1( vector<int>& dist, double hour) {
        int n = dist.size();
        if( n-1 > hour)return -1;
        int low = 1;
        int high = 0;
        for( int i: dist){
            high= max( high, i);
        }
        high = high * 100;
        int ans = INT_MAX;
        while( low <= high) {
            int mid = (high + low)/2;
            double time= findTime( dist, mid);
            //cout<<" time: "<<time<<" mid: "<<mid<<endl;
            if( time <= hour){
                high = mid - 1;
                ans= min( ans, mid);
            }
            else{
                low = mid + 1;
            }
        }
        return ans == INT_MAX ? -1: ans;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        return method1(dist,hour);
    }
};
