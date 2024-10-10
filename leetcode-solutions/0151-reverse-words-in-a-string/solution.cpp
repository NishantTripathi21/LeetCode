class Solution {
public:
    string reverseWords(string s){
        vector<string> words;
        string word = "";
        
        // Traverse the string and split into words
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' '){
                word += s[i];
            } 
            else if(!word.empty()){
                words.push_back(word);
                word = "";
            }
        }
        if (!word.empty()){
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result;
        for(int i = 0; i < words.size(); ++i){
            if (i > 0) result += " ";
            result += words[i];
        }
        return result;
    }
};
