class Solution {
public:
    bool satisfies( string &s){
        int n = s.size() -1;
        if( s[0] =='a' || s[0] == 'e' || s[0] =='i' || s[0]=='o' || s[0]=='u'){
            if(s[n] =='a' || s[n] == 'e' || s[n] =='i' || s[n]=='o' || s[n]=='u' ){
                return true;
            }
            return false;
        }
        return false;
    }
    vector<int> method1(vector<string>& words, vector<vector<int>>& queries){
        //using preFix sum
        // count number of strings that start and with a vowel and map count with index of string in words
        unordered_map<int,int>mp; //<index,count>
        mp[-1] = 0;
        int count = 0;
        for( int i = 0; i < words.size(); i++){
            if( satisfies(words[i])){
                count++;
            }
            //cout<<" index: "<<i<<" count: "<<count<<endl;
            mp[i] = count;
        }
        vector<int>ans;
        for( auto i: queries){
            int start = i[0];
            int end = i[1];
            int count = mp[end] - mp[start-1];
            ans.push_back(count);
        }
        return ans;
    } 
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        return method1(words,queries);
    }
};
