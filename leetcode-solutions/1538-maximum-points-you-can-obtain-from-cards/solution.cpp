class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left=0;
        int right=cardPoints.size()-1;
        int ans=0;
        int lSum=0;
        int rSum=0;
        for(int i=0;i<k;i++){
            lSum+= cardPoints[i];
        }
        ans=lSum;
        left = k-1;
        while( k ){
            lSum = lSum - cardPoints[left];
            left--;
            rSum=rSum + cardPoints[right];
            right--;
            ans = max( ans , lSum + rSum);
            k--;
        }
        return ans;
    }
};
