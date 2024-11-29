class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // exactly same question as  N meetings in one room
        sort(intervals.begin() , intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];     //sort by ending limit of each intervals
        });
        // cout<<" sorted array: "<<endl;
        // for( auto i: intervals){
        //     cout<<i[0] <<" "<<i[1] << endl;
        // }
        int lastEnd = intervals[0][1];
        int count = 1; // stores maximum number of non overlapping intervals
        int index = 1; 
        while( index < intervals.size()){
            if( intervals[index][0] >= lastEnd){// if next interval in not overlapping with previous one
                count++;
                lastEnd = intervals[index][1];
            }
            index++;
        }
        return intervals.size() - count ; // minimum number of overlapping intervals
    }
};
