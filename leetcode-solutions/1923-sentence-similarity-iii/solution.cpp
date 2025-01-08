class Solution {
public:
    bool method( string sen1, string sen2){
        if( sen1.size() < sen2.size()){
            swap( sen1, sen2);
        }
        vector<string>v1,v2;
        stringstream ss1(sen1);
        string token;
        while( ss1 >> token){
            v1.push_back(token);
        }
        stringstream ss2( sen2);
        string token2;
        while( ss2 >> token2){
            v2.push_back(token2);
        }
        int i = 0;
        int j = v1.size()-1;
        int k = 0;
        int l = v2.size()-1;
        while( i < v1.size() && k < v2.size() && v1[i] == v2[k]){
            i++;
            k++;
        }
        while(l >= k && v1[j] == v2[l]){
            j--;
            l--;
        }
        if( l < k)return true;
        return false;

    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        return method(sentence1, sentence2);
    }
};
