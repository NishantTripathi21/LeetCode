class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        int rabbits = 0;
        for(int i= 0; i< answers.size(); i++) {
            int sameColored = answers[i];
            if(mp.find(sameColored) == mp.end()) {
                mp[sameColored]= sameColored+1;
                rabbits += sameColored + 1;
            }
            mp[sameColored]--;
            if(mp[sameColored] <= 0) {
                mp.erase(sameColored);
            }                
        }
        
        return rabbits;
    }
};
