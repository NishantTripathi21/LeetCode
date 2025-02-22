class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = nums.size()-1;
        vector<int>ans(n);
        int position = n-1;
        while( left <= right) {
            int ele1 = abs(nums[left]);
            int ele2 = abs(nums[right]);
            if( ele1 > ele2) {
                ans[position] = ele1*ele1;
                left++;
                position--;
            }
            else{
                ans[position] = ele2*ele2;
                position--;
                right--;
            }
        }
        return ans;
    }
};
