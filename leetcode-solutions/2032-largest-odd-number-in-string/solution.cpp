class Solution {
public:
    string largestOddNumber(string num) {
        int ans=0;
        int index=num.size()-1;
        while(index >= 0){
            if(num[index]-'0' & 1){
                return num.substr(0,index+1);
            }
            index--;
        }
        return "";
    }
};
