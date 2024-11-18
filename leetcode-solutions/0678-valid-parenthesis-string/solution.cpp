class Solution {
public:
    bool checkValidString(string s) {
        int index =0;
        int mini = 0;// Tracks the minimum number of unmatched '(' after processing each character, considering '*' as
        // ')' or an empty string.
        int maxi = 0;// Tracks the maximum number of unmatched '(' after processing each character, 
        //considering '*' as '('.
        while(index < s.size()){
            char ch = s[index];
            if ( ch == '(' ){
                mini++; // one more unmatched found
                maxi++; // one more unmatched found
            }
            else if ( ch == ')'){
                mini--; // ')' alwyas matches with '('
                maxi--; 
            }
            else{
                mini--;  // considering * as ) , one more pair matches thus minimum unmatched decreases
                maxi++; // considering * as ( , one more pair unmatched, thus maximum count increases
            }
            if( mini < 0)mini = 0; // minimum matching should be more than zero;
            if( maxi < 0)return false; 
            index++;
        }
        return mini == 0;
    }
};

