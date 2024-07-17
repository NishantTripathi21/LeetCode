class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string>ans(numRows);
        int i=0;
        int row=0;
        bool direction=1;//1 means top to bottom and 0 means opposite
        while(true){
            if(direction){
                while(row<numRows && i<s.size()){
                    ans[row++].push_back(s[i++]);
                }
                row=numRows-2;
            }
            else{
                while(row>=0 && i<s.size()){
                 
               ans[row--].push_back(s[i++]);
                }
                row=1;
            }
            direction=!direction;
            if(i>=s.size()){
                break;
            }
            

        }
        string answer="";
            for(int j=0;j<ans.size();j++){
                answer+=ans[j];
                
            }
        return answer;
        
        
    }
};
