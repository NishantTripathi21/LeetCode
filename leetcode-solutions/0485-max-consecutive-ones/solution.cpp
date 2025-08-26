class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int ones = 0;
        for(int i: nums) {
            if(i == 1) {
                ones++;
                maxi = max(maxi,ones);
            }
            else if( i == 0) {
                ones = 0;
            }
        }
        return maxi;
    }
};
