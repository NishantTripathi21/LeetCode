class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        string s = to_string(n);
        int dec = s.size()-1;
        int index = 0;
        vector<int>ans;
        while(index < s.size()) {
            int num = pow(10, dec) * ((s[index]-'0'));
            dec--;
            index++;
            if(num == 0)continue;
            ans.push_back(num);
        }
        return ans;
    }
};
