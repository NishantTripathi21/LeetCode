class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int, int> position;
        for (int i = 0; i < order.size(); i++) {
            position[order[i]] = i;
        }
        
        sort(friends.begin(), friends.end(), [&](int a, int b) {
            return position[a] < position[b];
        });
    
        return friends;
    }
};
