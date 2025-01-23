class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word, lastWord;
        while (ss >> word) {
            lastWord = word;
        }

        return lastWord.length();
    }
};
