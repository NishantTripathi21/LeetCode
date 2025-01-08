class Solution {
public:
    long long method( string s){
        int n = s.size();
        if( n < 2)return 0;
        int i = 0;
        //int zeros = 0;
        long long swaps = 0;
        long long ones = 0;
        
        while( i < n){
            if( s[i] == '1'){
                ones++;
            }
            else{
                swaps += ones*1; 
            }
            i++;
        }
        return swaps;
        
    }
    long long minimumSteps(string s) {
        return method(s) ;
    }
};
