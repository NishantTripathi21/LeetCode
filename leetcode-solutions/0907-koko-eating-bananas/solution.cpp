class Solution {
public: 
    long long hours(vector<int>& v, long long mid) {
        long long totalH = 0;
        long long n = v.size();
        for (long long i = 0; i < n; i++) {
            totalH += (v[i] + mid - 1) / mid;
        }
        return totalH;
    }

    int BSonAns(vector<int>& piles, int h) {
        long long low = 1; 
        long long high = 0;
        for (long long i : piles) {
            high = max(high, i);
        }
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long totalHours = hours(piles, mid);
            if (totalHours > h) {
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        return BSonAns(piles, h);
    }
};

