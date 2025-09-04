class Solution {
public:
    int findClosest(int x, int y, int z) {
        int s1 = abs(z-x);
        int s2 = abs(z-y);
        if(s2 > s1) {
            return 1;
        }
        else if(s2 < s1)return 2;
        return 0;
    }
};
