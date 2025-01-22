class Solution {
public:
    int n;
    bool isValid(vector<int>& nums, int mid, int p) {
        int i = 0;
        int pairs = 0;
        while(i < n-1) {
            if(nums[i+1] - nums[i] <= mid) {
                pairs++;
                i+=2;
            }
            else {
                i++;
            }
        }
        return pairs >= p;
    }
    int method(vector<int>& nums, int p) {
        n = nums.size();
        sort(begin(nums), end(nums));
        int low = 0;
        int high = nums[n-1] - nums[0];
        int result = INT_MAX;
        while(low <= high) {
            
            int mid = low + (high-low)/2;
            
            if(isValid(nums, mid, p)) {
                result = mid;
                high = mid-1;
            } 
            else{
                low = mid+1;
            }
        }
        return result;
    }
    int minimizeMax(vector<int>& nums, int p) {
        return method(nums,p);
    }
};
