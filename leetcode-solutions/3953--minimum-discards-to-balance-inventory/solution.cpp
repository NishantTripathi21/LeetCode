class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int left = 0;
        int right = 0;
        unordered_set<int>discarded;
        unordered_map<int,int>appeared;
        //vector<int>lefts;
        int n = arrivals.size();
        while(right < n) {
            int type = arrivals[right];
            if(appeared[type] + 1 <= m) {
                //lefts.push_back(right);
                appeared[type]++;
            }
            else{
                cout<<" discarded index: "<<right<<endl;
                discarded.insert(right);
            }
            if(right - left + 1 == w) {
                if(discarded.find(left) == discarded.end()) {
                    appeared[arrivals[left]]--;
                }
                left++;
            }
            right++;
        }
        return discarded.size();
    }
};
