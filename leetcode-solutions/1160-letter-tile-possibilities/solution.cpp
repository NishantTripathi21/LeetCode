class Solution {
public:
    long long factorial(int n) {
        long long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    // Function to calculate distinct permutations
    long long countPermutations(string s) {
        int n = s.length();
        map<char, int> freq;

        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Apply the formula: n! / (f1! * f2! * ... * fk!)
        long long numerator = factorial(n);
        long long denominator = 1;

        for (auto it : freq) {
            denominator *= factorial(it.second);
        }

        return numerator / denominator;
    }

    void rec(string& tiles, unordered_set<string>& st, int index,string built,int& ans ) {
        if( index >= tiles.size()){
            // check if built string is present in set or not, if not, consider it
            if( built.size() > 0 && st.find(built) == st.end()) {
                st.insert(built);
                int n = 
                ans += countPermutations(built);
            }
            return;
        }
        rec(tiles, st, index+1, built, ans);
        built += tiles[index];
        
        //include
        if (st.find(built) == st.end()) {
            st.insert(built);
            ans += countPermutations(built);
        }
        //cout<<" built: "<<built<<" ans: "<<ans<<endl;
        rec(tiles,st,index+1,built,ans);
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        unordered_set<string>st;
        int ans = 0;
        rec(tiles,st,0,"",ans);
        return ans;

    }
};
