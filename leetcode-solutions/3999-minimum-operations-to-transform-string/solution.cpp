class Solution {
public:
    int minOperations(string s) {
        set<int>mySet;
        for(int i= 0; i< s.size(); i++) {
            char ch = s[i];
            int asci = ch - 'a';
            if(asci != 0)mySet.insert(asci);
        }
        int count = 0;
        while(!mySet.empty()) {
            int firstElement = *mySet.begin();
            mySet.erase(mySet.begin());
            firstElement = (firstElement + 1) % 26;
            count++;
            if(firstElement != 0) {
                mySet.insert(firstElement);
            }
        }
        return count;
    }
};
