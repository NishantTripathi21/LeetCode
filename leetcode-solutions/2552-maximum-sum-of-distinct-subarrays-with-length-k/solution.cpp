class Solution {
public:
    long long method( vector<int>& nums, int k){
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int,int>mp;
        long long sum = 0;
        long long maxSum = 0;
        while( right < nums.size()){
            sum += nums[right];
            if( mp.find(nums[right]) != mp.end()){
                //cout<<" count increased ";
                count++;
            }
            mp[nums[right]]++;
            //cout<<" left: "<<left<<" right: "<<right;
            if( right - left + 1 >= k){
                //cout<<" size of k size: ";
                if( mp.size() == k && count == 0){
                    maxSum = max( maxSum, sum);
                    //cout<<" updating maxSum: "<<maxSum;
                }
                mp[nums[left]]--;
                if( mp[nums[left]] > 0){
                    count--;
                    //cout<<"  decreasing count: "<<count;
                }
                if( mp[nums[left]] == 0){
                    //cout<<" erasing left: "<< nums[left];
                    mp.erase(nums[left]);
                }
                sum -= nums[left];
                left++;
            }
            right++;
            //cout<<endl;
        }
        return maxSum;
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {
        return method(nums,k);
    }
};
