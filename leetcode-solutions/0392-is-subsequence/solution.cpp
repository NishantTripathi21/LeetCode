class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i =0;
        int j = 0;
        int n1= s.size();
        int n2= t.size();
        if( n1 > n2)return false;
        while ( i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        return i == n1;
    }
};
