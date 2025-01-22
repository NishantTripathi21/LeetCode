class Solution {
public:
    bool isPossible( vector<int>& quen,int amount,int totalShops ){
        int count = 0;
        for( int i: quen) {
            count += ceil((double)i/(double)amount);
            if( count > totalShops)return false;
        }
        return count <= totalShops;
    }
    int method(  int n, vector<int>& quen) {
        int low = 1;
        int high = *max_element(quen.begin(),quen.end());
        int ans = 0;
        while( low <= high) {
            int mid = (low+high)/2;
            if( isPossible( quen, mid, n)){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        return method(n,quantities);
    }
};
