class Solution {
public:
bool isVowel(char ch){
    return (ch == 'A' || ch == 'E' || ch == 'O' || ch == 'I' || ch == 'U' || 
            ch == 'a' || ch == 'e'  || ch == 'o' || ch == 'i' || ch == 'u');
}
    string reverseVowels(string s) {
        string vowel = "";
        for(int i=0;i<s.size();i++){
            char ch = s[i];;
            if(isVowel(ch)){
                vowel += ch;
            }
        }
        int index = vowel.size()-1;
        for(int i=0;i<s.size();i++){
           if(isVowel(s[i])){
            s[i] = vowel[index--];
           }
        }
        return s;
    }
};
