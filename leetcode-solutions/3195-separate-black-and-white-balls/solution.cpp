class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;
        string t = s;
        sort(t.begin(),t.end());

        int i= s.size()-1 , j = s.size()-1;

        while( i >= 0){
            while(i >= 0 && s[i] == '0') i--;
            if(i < 0) break;
            count += 1LL* (j - i);
            i--;
            j--;
        }

        return count;
    }
};
