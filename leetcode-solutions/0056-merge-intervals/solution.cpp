class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for(auto& interval : intervals){
            auto& last = merged.back();
            if(interval[0] <= last[1]){
                // Overlapping intervals, merge them
                last[1] =max(last[1], interval[1]);
            } 
            else{
                // No overlap, add the interval to the result
                merged.push_back(interval);
            }
        }
        return merged;  
    }
};
