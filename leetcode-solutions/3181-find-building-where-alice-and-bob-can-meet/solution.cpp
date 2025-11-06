class Solution {
public:
    void buildSegTree(vector<int>& nums, vector<int>& segT, int segIndex, int l, int r) {
        if(l == r) {
            segT[segIndex] = l;
            return;
        }
        int mid = (l+r)/2;
        buildSegTree(nums,segT,segIndex*2+1, l, mid);
        buildSegTree(nums, segT, segIndex*2+2, mid+1, r);

        int leftIndex = segT[segIndex*2+1];
        int rightIndex = segT[segIndex*2+2];
        if(nums[leftIndex] >= nums[rightIndex]) {
            segT[segIndex] = leftIndex;
        }
        else segT[segIndex] = rightIndex;
    }

    int getMaxIndex(vector<int>& nums, vector<int>& segT, int start, int end, int segIndex, int l, int r) {
        if( r < start || l > end) return -1;

        if ( l >= start && r <= end) {
            return segT[segIndex];
        }

        else {
            int mid = (l+r)/2;
            int left = getMaxIndex(nums, segT,start,end,segIndex*2+1,l,mid);
            int right = getMaxIndex(nums, segT, start, end, segIndex*2+2, mid+1, r);
            if(left == -1)return right;
            if(right == -1)return left;
            if(nums[left] >= nums[right]) {
                return left;
            }
            else return right;
        }
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int>segT(4*n,0);
        buildSegTree(heights, segT, 0, 0, n-1);
        vector<int>result;
        for(auto query: queries) {
            int alice = min(query[0],query[1]);
            int bob   = max(query[0],query[1]);
            if(alice == bob || heights[bob] > heights[alice]){
                result.push_back(bob);
                continue;
            }
            int low = bob+1;
            int high = n-1;
            int ans = -1;
            while(low <= high) {
                int mid = (low+high)/2;
                int queryAns = getMaxIndex(heights, segT,low, mid, 0, 0, n-1);
                if( queryAns != -1 && heights[queryAns] > max(heights[alice],heights[bob])) {
                    ans  = queryAns;
                    high = mid - 1; 
                }
                else {
                    low = mid + 1;
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};
