class Solution {
public:
    vector<int> method1( vector<int>& security, int time){
        // using preFix sum algo
        vector<int>leftCondition( security.size(),0);
        int check = 0;
        for( int i= 0; i< security.size(); i++){
            if( i > 0 && security[i] <= security[i-1]){
                check++;
            }
            else{
                check = 0;
            }
            if( i >= time && check >= time){
                //cout<<" index: "<<i<<" ";
                leftCondition[i] = 1;
            }
        }
        vector<int>ans;
        check = 0;
        // verifying right condition
        for( int i= security.size()-1; i>= 0; i--){
            if( i < security.size()-1 && security[i] <= security[i+1]){
                check++;
            }
            else{
                check = 0;
            }
            if( check >= time && leftCondition[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        return method1(security, time);
    }
};
