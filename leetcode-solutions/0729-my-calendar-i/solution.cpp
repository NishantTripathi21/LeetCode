class MyCalendar {
public:
    vector<pair<int,int>>arr;
    MyCalendar() {
    }  
    bool book(int start, int end) {
        for(auto& temp : arr){
            if(max(temp.first, start) < min(temp.second, end)){
                return false;  // Overlap detected
            }
        }
        // No overlap
        arr.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
