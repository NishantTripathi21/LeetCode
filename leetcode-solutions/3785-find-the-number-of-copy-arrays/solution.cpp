class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int minPossible = INT_MIN;
        int maxPossible = INT_MAX;
        for(int i= 0; i< original.size(); i++) {
            int diff = original[i] - original[0];
            int minValue = bounds[i][0] - diff;
            int maxValue = bounds[i][1] - diff;
            
            minPossible = max(minPossible, minValue);
            maxPossible = min(maxPossible, maxValue);
            
        }
        return max(0,maxPossible - minPossible + 1);
    }
};
