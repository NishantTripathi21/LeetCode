class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        char str=needle[0];
        for(int i=0;i<n;i++){
            if(haystack[i]==str){
                int index=0;
                for(int j=0;j<m;j++){
                    if(haystack[i+j]==needle[j]){
                        index++;
                    }
                    else{
                        index=0;
                        break;
                    }
                }
                if(index==m){
                    return i;
                }
            }
            
        }
        return -1;
    }
};
