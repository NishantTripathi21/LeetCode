class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> resultSet;
        
        // Compare each word with every other word
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    resultSet.insert(words[i]);
                }
            }
        }
        
        // Convert set to vector
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};
