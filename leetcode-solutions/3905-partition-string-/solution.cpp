class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string>result;
        string temp = "";
        int index = 0;
        unordered_set<string>st;
        while(index < s.size()) {
            char ch= s[index];
            temp += ch;
            if( st.find(temp) == st.end()) {
                //cout<<" temp: "<<temp<<endl;
                st.insert(temp);
                result.push_back(temp);
                temp = "";
            }
            index++;
        }
        return result;
    }
};
