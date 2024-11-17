class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int pIndex=0;
        int tIndex=0;
        int ans=0;
        while( pIndex < players.size() && tIndex < trainers.size()){
            if( players[pIndex] <= trainers[tIndex] ){
                ans++;
                pIndex++;
                tIndex++;
            }
            else{
                tIndex++;
            }
        }
        return ans;
    }
};
