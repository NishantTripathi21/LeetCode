class Solution {
public:
    long long flowerGame(int n, int m) {
        int odds1 = n/2 + n%2;
        int even1= n/2;
        int odds2 = m/2 + m%2;
        int even2= m/2;
        // x+y == odd;
        // x = odd, y= even
        // x == even, y== odd
        long long ans = (long long)odds1 * even2 + (long long)even1 * odds2;
        return ans;
    }
};
