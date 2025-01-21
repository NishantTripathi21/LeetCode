class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long lcm(long long a, long long b, long long c) {
        return lcm(lcm(a, b), c);
    }

    long long count(long long mid, int a, int b, int c) {
        long long divA = mid / a;
        long long divB = mid / b;
        long long divC = mid / c;
        long long divAB = mid / lcm(a, b);
        long long divBC = mid / lcm(b, c);
        long long divAC = mid / lcm(a, c);
        long long divABC = mid / lcm(a, b, c);

        return divA + divB + divC - divAB - divBC - divAC + divABC;
    }

    int method(int n, int a, int b, int c) {
        long long low = 1;
        long long high = (long long)n * min({a, b, c});
        int ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid, a, b, c) >= n) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        return method(n, a, b, c);
    }
};

