class Solution {
public:
    bool isPrime(long long x) {
        if (x <= 1) return false;
        if (x <= 3) return true;
        if (x % 2 == 0 || x % 3 == 0) return false;
        for (long long i = 5; i * i <= x; i += 6) {
            if (x % i == 0 || x % (i + 2) == 0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        if (num < 0) return false;         
        string str = to_string(num);
        int n = str.size();
        for (int k = 1; k <= n; ++k) {
            int p = stoi(str.substr(0, k));
            if (!isPrime(p)) return false;
            int s = stoi(str.substr(n - k));
            if (!isPrime(s)) return false;
        }

        return true;
    }
};
