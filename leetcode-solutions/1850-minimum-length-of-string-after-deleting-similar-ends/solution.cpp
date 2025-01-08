class Solution {
public:
    int sol( string s){
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while( i < j && s[i] == s[j]){
            while( i< j-1 && s[i] == s[j] && s[i] == s[i+1]) {
                i++;
            }
            while( j > i+1 && s[j] == s[i] && s[j] == s[j-1]){
                j--;
            }
            i++;
            j--;
            // cout<<" i: "<<i<<" ";
            // cout<<" j: "<<j<<" "<<endl;
        }
        return j - i + 1;
    }
    int minimumLength(string s) {
        return sol(s);
    }
};
