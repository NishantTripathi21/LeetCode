class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>mp;
        int mini= INT_MAX;
        for(int i= 0; i< cards.size(); i++) {
            int val = cards[i];;
            if(mp.find(val) != mp.end()) {
                mini= min(mini, i - mp[val] + 1);
            }
            mp[val] = i;
        }
        return mini == INT_MAX ? -1: mini;
    }
};
