class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftTrack(n,0); //stictly increasing
        vector<int>rightTrack(n,0);
        int index = 1;
        leftTrack[0] = 1;
        while(index < n) {
            if(nums[index] > nums[index-1]) {
                leftTrack[index] = 1;
                index++;
            }
            else break;
        }
        int rindex = n-1;
        rightTrack[rindex] = 1;
        rindex--;
        while(rindex >= 0) {
            if(nums[rindex] > nums[rindex+1]) {
                rightTrack[rindex] = 1;
                rindex--;
            }
            else break;
        }
        if(index <= rindex)return -1;
        long long tsum = accumulate(nums.begin(),nums.end(),0LL);
        index = 0;
        long long lsum = 0;
        long long mini = LLONG_MAX;
        while(index < n-1) {
            lsum += (long long)nums[index];
            long long rsum = tsum - lsum;
            if(leftTrack[index] && rightTrack[index+1]){
                mini = min(mini,llabs(lsum-rsum));
            }
            index++;
        }
        return mini;
    }
};
