class Solution {
public:
    string largestMerge(string w1, string w2) {
        string merge;
        int i = 0;
        int j = 0;
        int n1 = w1.size();
        int n2 = w2.size();
        while( i < w1.size() && j < w2.size()){
            if( w1[i] > w2[j]){
                merge.push_back(w1[i]);
                i++;
            }
            else if( w1[i] < w2[j]){
                merge.push_back(w2[j]);
                j++;
            }
            else{
                // When w1[i] == w2[j] ,compare subsequent characters
                int tempI = i, tempJ = j;
                while(tempI < n1 && tempJ < n2 && w1[tempI] == w2[tempJ]){
                    tempI++;
                    tempJ++;
                }
                if(tempI < n1 && (tempJ == n2 || w1[tempI] > w2[tempJ])){
                    merge.push_back(w1[i]);
                    i++;
                } 
                else{
                    merge.push_back(w2[j]);
                    j++;
                }
            }
        }
        while( j < n2){
            merge += w2[j];
            j++;
        }
        while( i < n1){
            merge += w1[i];
            i++;
        }
        return merge;
    }

};
