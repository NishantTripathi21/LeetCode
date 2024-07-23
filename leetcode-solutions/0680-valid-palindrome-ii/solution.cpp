class Solution {
public:
    bool isPalindrome(string &s,int i, int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;

            }
            else{
                return false;
            }
        }
        return true;

    }
    bool validPalindrome(string s) {
        int j=s.size()-1;
        int i=0;
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                bool ans1=isPalindrome(s,i+1,j);
                bool ans2=isPalindrome(s,i,j-1);
                return ans1||ans2;
            }
        } 
        return true;

    }
};
