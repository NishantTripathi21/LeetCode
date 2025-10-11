class ExamTracker {
public:
    vector<pair<int,long long>>tsc;
    vector<int>times;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        long long prefix = score;
        if (!tsc.empty()) prefix += tsc.back().second;
        tsc.push_back({time, prefix});
        times.push_back(time);
    }
    
    long long totalScore(int startTime, int endTime) {
        if (tsc.empty()) return 0;
        int i1 = lower_bound(times.begin(), times.end(), startTime) - times.begin();
        int i2 = upper_bound(times.begin(), times.end(), endTime) - times.begin() - 1;
        if (i1 >= (int)times.size() || i2 < 0 || i1 > i2) return 0;
        long long total = tsc[i2].second;
        if (i1 > 0) total -= tsc[i1 - 1].second;
        return total;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
