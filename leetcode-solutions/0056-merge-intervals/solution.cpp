class Solution {
public:
    vector<vector<int>> sol( vector<vector<int>>& intervals){
        if( intervals.empty())return {};
        sort( intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        merged.push_back(intervals[0]);
        for( auto interval: intervals){
            auto& last = merged.back();
            if( last[1] >= interval[0]){
                last[1] = max( last[1],interval[1]);
            }
            else{
                merged.push_back(interval);
            }
        }
        return merged;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return sol(intervals);  
    }
};
