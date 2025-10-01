class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int empty = 0;
        while(numBottles) {
            ans += numBottles;
            empty = empty + numBottles;
            numBottles = empty/numExchange;
            empty = empty % numExchange;
        }
        ans += numBottles;
        return ans;
    }
};
