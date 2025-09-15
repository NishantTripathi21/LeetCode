class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        string st;
        stringstream ss(text);
        int total = 0;
        int untype = 0;
        unordered_set<char>mp(brokenLetters.begin(),brokenLetters.end());
        while(ss >> st) {
            total++;
            for(char ch: st) {
                if(mp.find(ch) != mp.end()) {
                    untype++;
                    break;
                }
            }
        }
        return total - untype;
    }
};
