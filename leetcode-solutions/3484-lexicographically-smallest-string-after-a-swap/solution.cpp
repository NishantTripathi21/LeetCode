class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for(int i=0;i<n-1;i++){
            int first = s[i] -'0';
            int second = s[i+1] -'0';

            if(first%2 == 0 && second%2 == 0){
                if(first > second) {
                    swap(s[i],s[i+1]);
                    break;
                }
            }
            if(first%2 != 0 && second%2 != 0){
                if(first > second) {
                    swap(s[i],s[i+1]);
                    break;
                }
            }
        }

        return s;
    }
};
