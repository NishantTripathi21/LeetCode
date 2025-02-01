class Solution {
public:
    struct Compare {
        bool operator()(const string& a, const string& b) {
            if (a.size() == b.size()) {
                int i= 0;int j = 0;
                while( i< a.size() && j < b.size()) {
                    if(a[i] != b[j]){
                        return a[i] > b[j];
                    }
                    i++;
                    j++;
                }
            }
            return a.size() > b.size(); 
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string >,  Compare> minHeap;
        for( string i: nums) {
            //long long num = stoll(i);
            minHeap.push(i);
            if( minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return (minHeap.top());
    }
};
