class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string>res;

        for(int i= 0;  i< logs.size(); i++) {
            string str = logs[i];
            cout<<" "<<str;
            if(str == "./")continue;
            else if(str == "../"){
                if(!res.empty()) {
                    res.pop_back();
                }
            }
            else res.push_back(str);
        }
        return res.size();
    }
};
