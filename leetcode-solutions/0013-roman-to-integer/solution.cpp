class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>map;
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            char ch=s[i];
            if(i+1 < s.size()){
                if(map[s[i+1]] > map[s[i]]){
                    ans=ans-map[s[i]];
                }
                else{
                    ans=ans+map[s[i]];
                }
            }
            else{
                ans=ans+map[s[i]];
            }
        }
        return ans;
    }
};
