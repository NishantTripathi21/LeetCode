class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int k) {
        int n = nums.size();
        int count = 0;
        for(int i= 0; i< nums.size(); i++) {
            if(nums[i] <= mid) {
                count++;
                i++;
            }
            if(count >= k)return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low <= high) {
            int mid = low - (low - high)/2;
            if(isPossible(nums,mid,k)) {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
