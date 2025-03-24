class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n = meetings.size();
        int start = 1;
        int last  = days;
        int curr = start;
        int gaps = 0;
        if(n && start < meetings[0][0]) {
            gaps += meetings[0][0] - start;
        }
        start = meetings[0][1];
        for(int i= 1; i< meetings.size();  i++) {
            auto it = meetings[i];
            int st = it[0];
            int ed = it[1];
            if(st > start) {
                gaps += st - start-1;
            }
            start = max(ed,start);
        }
        if(start < last){
            gaps += last - start;
        }
        return gaps;
    }
};
