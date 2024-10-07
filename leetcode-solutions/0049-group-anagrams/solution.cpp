class Solution {
public:
    array<int,256>hash(string str){//this is one more method to declare  array in cpp, it has stls. 
        array<int,256>hash={0};
        for(int i=0;i<str.size();i++){
            hash[str[i]]++;
        }
        return  hash;
    }
    vector<vector<string>> groupAnagramsM2(vector<string>& strs) {
        // M2 uses hashng concept and mapping concept, where key is an stl array and value is an vector of strings
        map<array<int,256>,vector<string>>mp;
        for(auto str:strs){
            mp[hash(str)].push_back(str);


        }
        vector<vector<string>>ans;
        for(auto ab=mp.begin();ab!=mp.end();ab++){// iterating through every key value pair in mp map
            ans.push_back(ab->second);// this is how value of mapped is accessed in cpp
        }
        return ans;

        
    }
    vector<vector<string>> groupAnagramsM1(vector<string>& strs) {
        // this method is by sorting and creating map , alernate method can by using of hash table instead of sorting coupled with mapping
        map<string,vector<string>>mp;
        for(auto str:strs){
            string s=str;
            sort(s.begin(),s.end());// sorting of string for anagram
            mp[s].push_back(str);// mapping of sorted anagram with orginal strings, every anagram will be mapped to its sorted anagram .for example eat,tea,ate will be  mapped with aet.


        }
        vector<vector<string>>ans;
        for(auto ab=mp.begin();ab!=mp.end();ab++){// iterating through every key value pair in mp map
            ans.push_back(ab->second);// this is how value of mapped is accessed in cpp
        }
        return ans;

        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //code your answer here
        return groupAnagramsM2(strs);

    }
};
