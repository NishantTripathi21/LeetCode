class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0;
        int right = 0;
        int whiteCount = 0;
        int minToRecolor = INT_MAX;
        while(right < blocks.size()) {
            if( blocks[right] == 'W') {
                whiteCount++;
            }
            int windowSize = right- left + 1;
            if(windowSize == k) {
                minToRecolor = min(minToRecolor,whiteCount);

                // shrink window
                if(blocks[left] == 'W') {
                    whiteCount--;
                }
                left++;
            }
            right++;
        }
        return minToRecolor;
    }
};
