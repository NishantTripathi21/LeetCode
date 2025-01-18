class TimeMap {
public:
unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }
        
        auto& values = store[key];
        int low = 0, high = values.size() - 1;
        string result = "";

        // Binary search for the greatest timestamp <= given timestamp
        while (low <= high) {
            int mid = (low + high) / 2;
            if(values[mid].first <= timestamp){
                result = values[mid].second; 
                low = mid + 1;
            } 
            else{
                high = mid - 1;
            }
        }
        
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
