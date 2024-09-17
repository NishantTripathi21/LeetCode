class Solution {
public:
    void printArry(vector<string>str){
        for(auto st:str){
            cout<<st<<" ";
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        vector<string> ans;

        // Combine both sentences
        stringstream ss(s1 + " " + s2);
        string word;

        // Count occurrences of each word
        while (ss >> word) {
            wordCount[word]++;
        }

        // Find uncommon words (those that appear exactly once)
        for (const auto& entry : wordCount) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};
