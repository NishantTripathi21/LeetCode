class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        string user = "";
        int maxCount = 0;
        unordered_map<string,int> mpp;
        for(int i=0;i<messages.size();i++){
            int count = 1;
            int index = 0;
            while(index < messages[i].size()){
                if(messages[i][index++] == ' ') count++;
            }

            mpp[senders[i]] += count;
            count =  mpp[senders[i]];
            if(count == maxCount) user = max(user,senders[i]);
            if(count > maxCount){
                user = senders[i];
                maxCount = count;
            }
        }

        return user;
    }
};
