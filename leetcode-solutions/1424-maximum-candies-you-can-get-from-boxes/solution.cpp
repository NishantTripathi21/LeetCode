class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size();
        queue<int> q;  
        unordered_set<int> availableKeys;  
        unordered_set<int> availableBoxes; 
        unordered_set<int> lockedBoxes;  // Stores locked boxes waiting for keys
        int ans = 0;

        for (int box : initialBoxes) {
            availableBoxes.insert(box);
            if (status[box] == 1) { 
                q.push(box);
            }
            else {
                lockedBoxes.insert(box);
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            ans += candies[box];
            for (int key : keys[box]) {
                availableKeys.insert(key);
                if (lockedBoxes.find(key) != lockedBoxes.end()) {
                    q.push(key);
                    lockedBoxes.erase(key);
                }
            }

            for (int newBox : containedBoxes[box]) {
                availableBoxes.insert(newBox);
                if (status[newBox] == 1 || availableKeys.count(newBox)) {
                    q.push(newBox);
                }
                else {
                    lockedBoxes.insert(newBox);
                }
            }
        }

        return ans;
    }
};
