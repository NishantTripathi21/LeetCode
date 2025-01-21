class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
    bool canDistribute(int maxInt, int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long total = maxInt;
        long long div1 = maxInt / divisor1;
        long long div2 = maxInt / divisor2;
        long long both = maxInt / lcm(divisor1, divisor2);

        long long notDiv1 = total - div1;
        long long notDiv2 = total - div2;
        long long notBoth = total - both;

        if (notDiv1 < uniqueCnt1 || notDiv2 < uniqueCnt2) {
            return false;
        }
        return notBoth >= uniqueCnt1 + uniqueCnt2;
    }
    int method( int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long low = 1; 
        long long high =INT_MAX;
        long long result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canDistribute(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return result;
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        return method( divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    }
};
