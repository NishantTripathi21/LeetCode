class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string t = "";
        for(char c : s) {
            if (c != '0') t += c;
        }
        if (t.empty()) return 0;
        long long x = stoll(t);
        long long sum = 0;
        for(char c : t) sum += (c - '0');
        return x * sum;
    }
};
