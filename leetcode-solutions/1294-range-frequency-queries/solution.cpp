class RangeFreqQuery {
public:
    map<int, vector<int>> indexMap;
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            indexMap[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (indexMap.find(value) == indexMap.end()) {
            return 0;
        }
        vector<int>& indices = indexMap[value];
        auto leftBound = lower_bound(indices.begin(), indices.end(), left);
        auto rightBound = upper_bound(indices.begin(), indices.end(), right);
        
        return rightBound - leftBound;
    }
    
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
