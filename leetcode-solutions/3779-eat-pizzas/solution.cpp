class Solution {
public:
    long long maxWeight(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int days = n / 4;
        //cout<<days;
        int odd = ceil(days/2.0);
        long long result = 0;
        int even = days - odd;
        //cout<<" odd: "<<odd<<" even: "<<even<<endl;
        int right = n-1;
        //cout<<" odd ";
        while( odd--) {
            //cout<<" nums[right]: "<<nums[right]<<endl;
            result += nums[right--];
        }
        right--;
        //cout<<" even ";
        while( even-- ) {
            //cout<<" nums[right]: "<<nums[right]<<endl;
            result += nums[right];
            right -= 2;
        }
        return result;
    }
};
