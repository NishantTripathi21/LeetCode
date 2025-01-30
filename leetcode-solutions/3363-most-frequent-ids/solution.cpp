class Solution {
public:
    typedef long long ll;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<ll, ll> mp; //{ID -> freq}
        vector<ll> result(nums.size());
        priority_queue<pair<ll, ll>>maxHeap; //{freq, ID} 
        for(int i=0; i <n; i++) {
            int ID = nums[i];
            int f  = freq[i];
            mp[ID] += f;
            maxHeap.push({mp[ID], ID});
            while(maxHeap.size() > 0 && mp[maxHeap.top().second] != maxHeap.top().first) {
                maxHeap.pop();
            }
            result[i] =maxHeap.top().first;
        }
        return result;
    
    }
};
