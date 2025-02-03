class Solution {
public:
    string minimizeStringValue(string s) {
        priority_queue<pair<int,char>, vector<pair<int,char>>,greater<pair<int,char>>>minHeap;
        int hash[26]={0};
        for(char ch: s) {
            if( ch != '?') {
                hash[ch-'a']++;
            }
        }
        for( int i = 0; i< 26; i++) {
            minHeap.push({hash[i], i + 'a' });
        }
        string result;
        for( int i= 0; i< s.size(); i++) {
            if(s[i] == '?'){
                auto top = minHeap.top();
                minHeap.pop();
                
                char ch = top.second;
                result += ch;
                minHeap.push({top.first+1, ch});
            }
        }
        sort(result.begin(),result.end());
        int i = 0;
        for( char& ch:s) {
            if( ch == '?'){
                ch = result[i];
                i++;
            }
        }
        return s;
    }
};
