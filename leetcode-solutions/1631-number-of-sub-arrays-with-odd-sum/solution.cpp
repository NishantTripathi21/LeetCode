class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int MOD= (long long)1e9+7;
        int n = nums.size();
        vector<int>oddEvenCount(2,0); //0 index - even sum count, 1 index - odd sum count
        oddEvenCount[0]++;
        long long sum = 0;
        long long count = 0;
        for( int i = 0; i< nums.size(); i++) {
            int ele = nums[i];
            sum += (long long)ele;
            if( sum & 1) {
                //sum is odd
                count += (long long)oddEvenCount[0];
                oddEvenCount[1]++;
            }
            else{
                // sum is even
                count +=(long long) oddEvenCount[1];
                oddEvenCount[0]++;
            }
        }
        return count%MOD;

    }
};
