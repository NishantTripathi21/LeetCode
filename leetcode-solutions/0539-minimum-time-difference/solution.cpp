class Solution {
public:
    int convertToMin(string &str){
        int totalMins=0;
        int hour=stoi(str.substr(0,2));
        int min=stoi(str.substr(3,2));
        totalMins=hour*60+min;
        return totalMins;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>mins;
        for(auto str: timePoints){
            mins.push_back(convertToMin(str));
        }
        sort(mins.begin(),mins.end());
        int mini=INT_MAX;
        for(int i=0;i<mins.size()-1;i++){
            mini=min(mini,(mins[i+1]-mins[i]));
        }
        int reverser_ans=1440+mins[0] - mins[mins.size()-1];
        mini=min(mini,reverser_ans);
        return mini;

    }
};
