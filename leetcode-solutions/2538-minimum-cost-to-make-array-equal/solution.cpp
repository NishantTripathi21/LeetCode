class Solution {
public:
    typedef long long ll;
    ll findCost( vector<int>& nums, vector<int>& cost, ll mid) {
        ll sum = 0;
        for( int i = 0; i< nums.size(); i++){
            sum += (ll)abs( nums[i] - mid)*cost[i];
        }
        return sum;
    }
    ll usingBS( vector<int>& nums, vector<int>& cost){
        ll answer = INT_MAX;
        int left = *min_element( nums.begin(),nums.end());
        int right = *max_element( nums.begin(), nums.end());

        while( left <= right){
            int mid = left + (right - left)/2;
            ll cost1 = findCost( nums,cost,mid);
            ll cost2 = findCost( nums,cost,mid+1);
            answer = min( cost1,cost2);
            if( cost1 < cost2){
                right = mid -1;
            }
            else{
                left = mid +1;
            }
        }
        return answer == INT_MAX ? 0 : answer;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        return usingBS( nums,cost);
    }
};
