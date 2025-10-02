class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = 0;
        int empty = 0;
        int filled = numBottles;
        while(filled) {
            count += filled;
            empty += filled;
            filled= 0;
            while(empty >= numExchange) {
                filled += 1;
                empty -= numExchange;
                numExchange++;
            }
        }
        return count;
    }
};
