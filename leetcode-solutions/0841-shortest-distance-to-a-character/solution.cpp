class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> answer(n, INT_MAX);
        int prev = -1;

        // left to right
        for (int i = 0; i < n; ++i){
            if (s[i] == c) {
                prev = i;
            }
            if( prev != -1){
                answer[i] = abs((i - prev));
            }
            
        }

        // right to left
        for (int i = n - 1; i >= 0; --i){
            if(s[i] == c){
                prev = i;
            }
            if( prev != -1){
                answer[i] = min(answer[i], abs(prev - i));
            }
            
        }

        return answer;
    }
};
