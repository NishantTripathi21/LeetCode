class Solution {
public:
    string addA(string s, int a){
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = ((s[i] - '0' + a) % 10) + '0';
        }
        return s;
    } 

    string rotate(string s, int b) {
        int n = s.size();
        b %= n;
        if (b == 0) return s;

        string t = s;
        for (int i = 0; i < b; i++) {
            s[i] = t[n - b + i];
        }
        for (int i = b; i < n; i++) {
            s[i] = t[i - b];
        }

        return s;
    }

    string findLexSmallestString(string s, int a, int b) {
        queue<string>q;
        unordered_set<string>vis;
        string ans = s;
        q.push(s);
        vis.insert(s);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            ans = min(ans,top);

            // add a
            string added = addA(top, a);
            if(vis.find(added) == vis.end()) {
                vis.insert(added);
                q.push(added);
            }
            //rotate
            string rt = rotate(top, b);
            if(vis.find(rt) == vis.end()) {
                vis.insert(rt);
                q.push(rt);
            }
        }
        return ans;
    }
};
