class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;
        for(int i= 0; i< tasks.size(); i++) {
            int st = tasks[i][0];
            int ed = tasks[i][1];
            ans = min(ans,ed+st);
        }
        return ans;
    }
};
