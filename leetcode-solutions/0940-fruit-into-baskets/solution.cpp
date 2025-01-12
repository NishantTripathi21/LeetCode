class Solution {
public:
    int method( vector<int>& nums){
        unordered_map<int,int>mp;
        int left = 0;
        int right = 0;
        int maxSize = 0;
        while( right < nums.size()){
            mp[nums[right]]++;
            while( mp.size() > 2){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            if( mp.size() <= 2){
                maxSize = max( maxSize, right-left+1);
            }
            right++;
        }
        return maxSize;
    }
    int totalFruit(vector<int>& fruits) {
        // maximum size subarray with maximum two distinct numbers
        return method(fruits);
    }
};
