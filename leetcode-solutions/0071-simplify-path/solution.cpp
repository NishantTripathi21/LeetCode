class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string>st;
        string token;
        while(getline(ss, token , '/')) {
            if(token == "." || token == "")continue;
            else if ( token != "..") {
                st.push_back(token);
            }
            else if(!st.empty()){
                st.pop_back();
            }
        }

        string res = "/";
        for (int i = 0; i < st.size(); i++) {
            res += st[i];
            if (i != st.size() - 1) res += "/";
        }
        return res;
        
    }
};
