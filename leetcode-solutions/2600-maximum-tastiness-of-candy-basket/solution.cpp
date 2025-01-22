class Solution {
public:
    bool possibleToPlace( vector<int>& pos, int m,int dist) {
        int count = 1;
        int placed = 0;
        for( int i = 0; i< pos.size();i++){
            if( abs(pos[placed] - pos[i]) >= dist){
                count++;
                placed = i;
            }
            if( count >= m)return true;
        }
        return count >= m;
    }
    int method( vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int low = 0;
        int high = pos[pos.size()-1] - pos[0];
        int ans = 0;
        while( low <= high) {
            int mid = (low+high)/2;
            if( possibleToPlace(pos,m,mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& position, int m) {
        //code copied from LC- 1552
        return method(position,m);
    }
    int maximumTastiness(vector<int>& price, int k) {
        return maxDistance(price,k);
    }
};
