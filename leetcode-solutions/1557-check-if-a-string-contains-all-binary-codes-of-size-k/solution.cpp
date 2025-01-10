class Solution {
public:
    bool implement( string s , int k){
        int count = pow(2,k); //2^k
        set<string>codes;
        int left = 0;
        int right = 0;
        while( right < s.size()){
            //cout<<" right: "<<right<<"  left: "<<left; 
            if( right - left + 1 >= k){
                string str = s.substr( left,(right-left+1));
                //cout<<" str: "<<str;
                codes.insert(str);
                left++;
            }
            right++;
            //cout<<endl;
        }
        return count == codes.size();
    }
    bool hasAllCodes(string s, int k) {
        return implement(s,k);
    }
};
