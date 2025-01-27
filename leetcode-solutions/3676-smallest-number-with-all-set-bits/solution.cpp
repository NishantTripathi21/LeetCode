class Solution {
public:
    int smallestNumber(int n) {
        for( int i= 0; i<= 10; i++){
            int p = pow(2,i);
            if( p > n)return p-1;
        }
        return -1;
    }
};
