class Solution {
public:
    static bool my_comp(string a, string b){// application of coustom comparator
        string a1=a+b;
        string b1=b+a;
        return a1>b1;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>snums;
        for(auto i:nums){
            snums.push_back(to_string(i));// converting number to string
        }
        sort(snums.begin(),snums.end(),my_comp );
        string ans="";
        if(snums[0]=="0"){
            return "0";
        }
        for(auto str:snums){
            ans+=str;
        }
        
        return ans;
        
    }
};
