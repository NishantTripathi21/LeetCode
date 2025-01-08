class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr= 1;
        int prev = 0;
        int index  = 1;
        int count = 0;
        while( index < s.size()){
            if( s[index]== s[index-1]){
                curr++;
            }
            else{
                count += min( curr, prev);
                prev = curr;
                curr = 1;
            }
            index++;
        } 
        count += min( curr, prev);
        return count;

    }
};
