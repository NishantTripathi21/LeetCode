class Solution {
public:
    bool method2(string s, string t){
        // this method is called solution by hashing , we created hash table(array of 267 elements in which every ascii value has its share)
        int maps[267]={0};
        for(int i=0;i<s.size();i++){
            maps[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            maps[t[i]]--;
        }
        for(int i=0;i<267;i++){
            if(maps[i]!=0){
                return false;
            }
            

        }
        return true;
        
    }
    bool isAnagram(string s, string t) {
    //  m1 sort both strings and ccompare, brute force
    // sort(s.begin(),s.end());
    // sort(t.begin(),t.end());

    // if(s==t){
    //     return true;
    // }
    // return false;
        
    // }
    return method2(s,t);
    }
};
