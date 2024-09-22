class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string>banned(bannedWords.begin(),bannedWords.end());
        int count=0;
        for(int i=0;i<message.size();i++){
            if(banned.find(message[i]) != banned.end() ){
                count=count + 1;
            }
            if(count >=2){
                return true;
                break;
            }
        }
        return false;
    }
};
