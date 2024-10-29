class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i=0;
        while(true){
            char cur_char=0;
            for(auto str: strs){
                if(i>=str.size()){
                    cur_char=0;
                    break;
                }
                if(cur_char==0){
                    cur_char=str[i];

                }
                else if(str[i]!=cur_char){
                    cur_char=0;
                    break;
                }
            }
             if(cur_char==0){
                break;
            }
            ans.push_back(cur_char);
            i++;
           
        }
        return ans;
        
    }
};
