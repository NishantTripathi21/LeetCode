class Solution {
public:
    int usingTabulationSpaceOptimisation(string &text1,string &text2){
        vector<int>prev(max(text1.size()+2,text2.size()+2),0);
        vector<int>curr(max(text1.size()+2,text2.size()+2),0);
        for(int col=text2.size()-1;col>=0;col--){
            for(int row=text1.size()-1;row>=0;row--){
                int ans=0;
                if(text1[row]==text2[col]){
                    ans=1+prev[row+1];
                }
                else{
                    ans=0 + max(prev[row],curr[row+1]);
                }
                curr[row]=ans;
            }
            prev=curr;

        }
        return curr[0];

    }
    int longestPalindromeSubseq(string s) {
        string reversed=s;
        reverse(reversed.begin(),reversed.end());
        return usingTabulationSpaceOptimisation(s,reversed);
    }
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};
