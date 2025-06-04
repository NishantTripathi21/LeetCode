class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int maxSize = n - numFriends + 1;
        if(numFriends == 1)return word;
        char largest = 'a';
        for(auto ch: word) {
            largest = max(largest,ch);
        }
        vector<string>prospects;
        for(int i= 0; i< word.size(); i++) {
            if(word[i] == largest) {
                auto temp = word.substr(i,maxSize);
                prospects.push_back(temp);
            }
        }
        sort(prospects.begin(),prospects.end());
        return prospects.back();
        
    }
};
