class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sumK=0;
        
        //sliding window approach
        for(int i=0;i<k;i++){
            sumK=sumK+nums[i];

        }
        double maxi=sumK;
        for(int i=k;i<nums.size();i++){
            sumK=sumK+nums[i]-nums[i-k];
            maxi=max(maxi,sumK);
        }
        return maxi/k;

    }
};
