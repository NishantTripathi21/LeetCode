class Solution {
public:
    void usingRec(string &digits,int index, vector<string>&ans,auto mapping,string &temp){
        if(index >= digits.size()){
            ans.push_back(temp);
            return ;
        }
        string letters=mapping[digits[index]];
        for(char letter:letters){
            temp.push_back(letter);
            usingRec(digits,index+1,ans,mapping,temp);
            temp.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mapping;
        mapping['2']="abc";
        mapping['3']="def";mapping['4']="ghi";mapping['5']="jkl";mapping['6']="mno";
        mapping['7']="pqrs";mapping['8']="tuv";mapping['9']="wxyz";
        for(auto i:mapping){
            cout<<i.second<<" ";
        }
        vector<string>ans;
        string str;
        if(digits.size()==0)return ans;
        usingRec(digits,0,ans,mapping, str);
        return ans;

    }
};
