class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'e') {
            return true;
        }
        return false;
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int>nextConsoIndex(n);
        int index = n;
        for(int i= n-1; i>= 0; i--) {
            nextConsoIndex[i] = index;
            if(!isVowel(word[i])) {
                index = i;
            }
        }
        unordered_map<char,int>mp;
        int left = 0, right = 0, consoCount = 0;
        long long ans = 0;
        while (right < word.size()) {
            char ch = word[right];
            if (isVowel(ch)) {
                mp[ch]++;
            }
            else {
                consoCount++;
            }
            while( consoCount > k) {
                char ch1 = word[left];
                if(isVowel(ch1)) {
                    mp[ch1]--;
                    if(mp[ch1] == 0)mp.erase(ch1);
                }
                else consoCount--;
                left++;
            }
            while( left < n && mp.size() == 5 && consoCount == k) {
                ans += nextConsoIndex[right] - right;
                char ch1 = word[left];
                if(isVowel(ch1)) {
                    mp[ch1]--;
                    if(mp[ch1] == 0){
                        mp.erase(ch1);
                    }
                }
                else consoCount--;
                left++;
            }
            right++;
            //cout<<right<<left<<endl;
        }
        return ans;
    }
};
