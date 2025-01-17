class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ub = upper_bound( letters.begin(),letters.end(),target) - letters.begin();
        int n = letters.size();
        if( ub >= n)return letters[0];
        return letters[ub];
    }
};
