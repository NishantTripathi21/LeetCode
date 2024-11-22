class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>left(ratings.size() , 1);
        //vector<int>right(ratings.size() , 1);
        int candy = 1;
        left[0]=candy;
        //right[ratings.size()-1] = 1;
        for( int i = 1; i < ratings.size() ; i++){
            if( ratings[i] > ratings[i-1]){
                candy++;
            }
            else{
                candy= 1;
            }
            left[i] = candy;
        }
        candy = 1;
        int ans = max(1 , left[ratings.size()-1]) ;
        for( int i = ratings.size()-2 ; i >=0 ; i--){
            if( ratings[i] > ratings[i+1]){
                candy++;
            }
            else{
                candy = 1;
            }
            //right[i] = candy;
            ans += max( left[i] , candy);
        }
        // for( int i = 0 ; i < ratings.size() ;i++){
        //     ans += max(left[i], right[i]);
        // }
        return ans;
    }
};
