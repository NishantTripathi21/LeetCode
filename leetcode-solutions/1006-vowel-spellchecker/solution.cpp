class Solution {
public:
    string maskVowels(string s) {
        for (char &c : s) {
            c = tolower(c);
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                c = '*';
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> original(wordlist.begin(), wordlist.end());
        unordered_map<string,string> lowerMap;
        unordered_map<string,string> vowelMap;

        for (string w : wordlist) {
            string lower = w;
            for (char &c : lower) c = tolower(c);

            if (!lowerMap.count(lower))
                lowerMap[lower] = w;

            string masked = maskVowels(lower);
            if (!vowelMap.count(masked))
                vowelMap[masked] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (original.count(q)) {
                ans.push_back(q);
                continue;
            }
            // Case insensitive match
            string lowerQ = q;
            for (char &c : lowerQ) c = tolower(c);
            if (lowerMap.count(lowerQ)) {
                ans.push_back(lowerMap[lowerQ]);
                continue;
            }
            //Vowel error match
            string maskedQ = maskVowels(lowerQ);
            if (vowelMap.count(maskedQ)) {
                ans.push_back(vowelMap[maskedQ]);
                continue;
            }
            ans.push_back("");
        }

        return ans;
    }
};
