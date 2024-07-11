class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'|| ch=='A'||ch=='E'|| ch=='I'|| ch=='O'|| ch=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int start=0;
        int end=s.size();
        while(start<=end){
            if(isVowel(s[start]) && isVowel(s[end])){
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(!isVowel(s[start])){
                start++;
            }
            else{
                end--;
            }
        }
        return s;
        
    }
};
