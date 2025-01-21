class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + (tiles[i][1] - tiles[i][0] + 1);
        }

        int maxCovered = 0;

        for (int i = 0; i < n; i++) {
            int start = tiles[i][0];
            int end = start + carpetLen - 1;

            int low = i, high = n - 1, pos = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (tiles[mid][1] <= end) {
                    pos = mid; // Fully covered interval
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            // Total tiles covered from i to pos
            int totalCovered = 0;
            if( pos != -1){
                totalCovered = prefixSum[pos + 1] - prefixSum[i];
            }
            else{
                totalCovered = carpetLen;
            }

            // Handle partial coverage of the next interval (if any)
            if (pos != -1 && pos + 1 < n && tiles[pos + 1][0] <= end) {
                totalCovered += end - tiles[pos + 1][0] + 1;
            }

            // Update maximum coverage
            maxCovered = max(maxCovered, totalCovered);
        }

        return maxCovered;
    }
};
