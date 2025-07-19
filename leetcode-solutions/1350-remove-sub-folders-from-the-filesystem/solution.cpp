class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
       sort(folder.begin(), folder.end());
        vector<string> result;
        string prev = "";
        
        for (const string& f : folder) {
            if (result.empty() || f.substr(0, prev.size()) != prev || f[prev.size()] != '/') {
                result.push_back(f);
                prev = f;
            }
        }
        
        return result; 
    }
};
