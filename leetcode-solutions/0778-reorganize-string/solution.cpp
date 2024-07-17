class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
                }
        //find most frequent element
        char most_frequent_char;
        int max_frequency=INT_MIN;
        for(int i=0;i<26;i++){
            if(hash[i]>max_frequency){
                max_frequency=hash[i];
                most_frequent_char=i + 'a';
            }
        }
        int index=0;
        while(max_frequency>0 && index<s.size() ){
            s[index]=most_frequent_char;
            index+=2;
            max_frequency--;
        }
        if(max_frequency> 0) return "";
        hash[most_frequent_char - 'a']=0;
        for(int i=0;i<26;i++){
            while(hash[i]> 0){
                index= index>=s.size()? 1 : index;
                s[index]=i+'a';
                index+=2;
                
                hash[i]--;
            }
        }
        return s;



    }
};
