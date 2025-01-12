class Solution {
public:
    int method( vector<int>& nums, int k){
        int left = 0;
        int right = 0;
        int ans = 0;
        int product = 1;
        while( right < nums.size()){
            product *= nums[right];
            while( product >= k && left <= right){
                product /= nums[left];
                left++;
            }
            //cout<<" right: "<<right<<" left: "<<left<<" product: "<<product<<endl;
            if( product < k){
                ans += right-left+1;
            }
            right++;
        }
        return ans;
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        return method( nums ,k);
    }
};
