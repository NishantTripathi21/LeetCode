class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(int a, int b) {
        return (1LL * a * b) / gcd(a, b);
    }
    bool possible(vector<int>& d, vector<int>& r, long long mid) {
        long long h1 = mid - mid/r[0];
        long long h2 = mid - mid/r[1];
        long long r1r2 = lcm(r[0],r[1]);
        long long both = mid - mid/r1r2;

        return d[0] <= h1 && d[1] <= h2 && d[0]+d[1] <= both;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long l = 0;
        long long h = 2e18;
        long long ans = h;
        while(l <= h) {
            long long mid = (h+l)/2;
            if(possible(d,r,mid)) {
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
