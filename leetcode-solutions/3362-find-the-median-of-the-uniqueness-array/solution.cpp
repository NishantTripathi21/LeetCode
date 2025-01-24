class Solution {
public:
    long long countSubarraysWithDistinctsLessOrEqualTo( vector<int>& nums, int mid) {
        unordered_map<int,int>mp;
        int left = 0;
        int right = 0;
        long long count = 0;
        while( right < nums.size()) {
            mp[nums[right]]++;
            while( mp.size() > mid){
                mp[nums[left]]--;
                if( mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            if( mp.size() <= mid){
                count = (long long)count + right-left+1;
            }
            right++;
        }
        return count;
    }
    int method( vector<int>& nums) {
        int low = 1;
        int high = 1;
        unordered_set<int> uniqueElements(nums.begin(), nums.end());
        high = uniqueElements.size();
        int ans = 0;
        int n = nums.size();
        long long totalSubarrays = (long long) n*(n+1)/2;
        long long medianPosition = (totalSubarrays + 1) / 2;
    
        while( low <= high) {
            int mid = (low+high)/2;
            long long numberOfSubarrays = countSubarraysWithDistinctsLessOrEqualTo(nums,mid);
            if( numberOfSubarrays >= medianPosition ){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int medianOfUniquenessArray(vector<int>& nums){
        return method(nums);
    }
};
