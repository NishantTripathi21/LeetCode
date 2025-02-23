class Solution {
public:
    bool hasSameDigits(string s) {
        string str = s;
        while(str.size() > 2) {
            string temp = "";
            for( int i= 0; i< str.size()-1; i++) {
                int a= (str[i])-'0';
                int b = (str[i+1])-'0';
                int sum = (a+b) % 10;
                temp += to_string(sum);
            }
            str = temp;
        }
        if( str.size() == 2){
            if(str[1]==str[0])return true;
        }
        return false;
    }
};
