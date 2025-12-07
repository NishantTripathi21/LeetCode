class Solution {
public:
    vector<int> getP(int n) {
        vector<bool>pF(n + 1, true);
        pF[0] = false;
        pF[1] = false;
        for (int x = 2; x * x <= n; x++) {
            if (pF[x]) {
                for (long long y = 1LL * x * x; y <= n; y += x) {
                    pF[y] = false;
                }
            }
        }
        vector<int> pL;
        for (int val = 2; val <= n; val++) {
            if (pF[val]) {
                pL.push_back(val);
            }
        }

        return pL;
    }
    int largestPrime(int n) {
        vector<int> primeSeq = getP(n);

        vector<bool> pC(n + 1, true);
        pC[0] = false;
        pC[1] = false;

        for (int base = 2; base * base <= n; base++) {
            if (pC[base]) {
                for (long long curr = 1LL * base * base; curr <= n; curr += base) {
                    pC[curr] = false;
                }
            }
        }

        long long t = 0;
        int ans = 0;

        for (int idx = 0; idx < (int)primeSeq.size(); idx++) {
            t += primeSeq[idx];
            if (t > n) {
                break;
            }
            if (pC[t]) {
                ans = (int)t;
            }
        }

        return ans;
    }
};
