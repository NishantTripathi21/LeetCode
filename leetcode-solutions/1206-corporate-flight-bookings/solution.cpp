class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>construct(n+1,0);
        for(int i= 0; i< bookings.size(); i++) {
            int start = bookings[i][0]-1;
            int end = bookings[i][1] ;
            int val = bookings[i][2];
            construct[start] += val;
            construct[end] -= val;
        }
        int sum = 0;
        construct.resize(n);
        for(int i= 0; i< n; i++) {
            sum += construct[i];
            construct[i] = sum;
        }
        return construct;
    }
};
