class Solution {
public:
    int firstUniqChar(string s) {
        queue<int>q;
        int freq[26]={0};
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
            q.push(i);
        }
        //answer find
        while(!q.empty()){
            char ch=s[q.front()];
            if(freq[ch-'a']>1){
                q.pop();
            }
            else{
                return q.front();
                break;
            }
        }
        return -1;

    }
};
