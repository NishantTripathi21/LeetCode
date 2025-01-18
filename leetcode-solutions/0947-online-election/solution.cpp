class TopVotedCandidate {
public:
    unordered_map<int,int>voteCount;
    vector<pair<int,int>>winTime;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int majorityVote = 0;
        int majorityPerson;
        for( int i= 0; i< persons.size(); i++) {
            int person = persons[i];
            int time = times[i];
            voteCount[person]++;
            if( voteCount[person] >= majorityVote){
                majorityVote = voteCount[person];
                majorityPerson = person;
                //winTime.push_back({time,majorityPerson});
            }
            winTime.push_back({time,majorityPerson});
        }
    }
    
    int q(int t) {
        int low = 0;
        int high = winTime.size() -1;
        while( low <= high){
            int mid = (low+high )/ 2;
            int time = winTime[mid].first;
            if( time > t){
                high = mid-1;
            }
            else if( time < t ){
                low = mid + 1;
            }
            else{
                return winTime[mid].second;
            }
        }
        return winTime[high].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
