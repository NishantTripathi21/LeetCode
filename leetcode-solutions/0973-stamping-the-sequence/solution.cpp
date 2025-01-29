class Solution {
public:
    bool canStamp(string& stamp,string& target, int start) {
        for (int i = 0; i < stamp.length(); i++){
            if (target[start + i] != '?' && target[start + i] != stamp[i]) {
                return false;
            }
        }
        return true;
    }
    int doStamp(const string& stamp, string& target, int start) {
        int count = 0;
        for (int i = 0; i < stamp.length(); i++) {
            if (target[start + i] != '?') {
                target[start + i] = '?';
                count++;
            }
        }
        return count;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.length();
        int n = target.length();
        vector<int> result;
        vector<bool> stamped(n, false);
        int count = 0;
        while (count < n){
            bool changed = false;
            for(int i = 0; i <= n - m; i++) {
                if(!stamped[i] && canStamp(stamp, target, i)) {
                    count += doStamp(stamp, target, i);
                    stamped[i] = true;
                    result.push_back(i);
                    changed = true;
                    if (count == n) break;
                }
            }
            if (!changed){
                return {};
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
