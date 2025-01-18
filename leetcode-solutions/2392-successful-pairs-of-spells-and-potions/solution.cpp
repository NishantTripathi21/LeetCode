class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        int m = potions.size();
        for( int i = 0; i< spells.size(); i++) {
            long long spellStrength = spells[i];
            int low = 0;
            int high = potions.size()-1;
            while( low <= high){
                int mid = (low+high)/2;
                long long product = spellStrength * (long long)potions[mid];
                if( product >= success){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            ans.push_back( m - high-1);
        }
        return ans;
    }
};
