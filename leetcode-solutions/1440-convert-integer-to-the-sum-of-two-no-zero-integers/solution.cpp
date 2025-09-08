class Solution {
public:
    bool containZero(int n) {
        string s = to_string(n);
        for(char ch: s) {
            if(ch == '0'){
                return true;
            }
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a = n-1;
        int b = 1;
        while(true) {
            if(containZero(a) || containZero(b)) {
                a--;
                b++;
            }
            else{
                return {a,b};
            }
        }
        return {};
    }
};
