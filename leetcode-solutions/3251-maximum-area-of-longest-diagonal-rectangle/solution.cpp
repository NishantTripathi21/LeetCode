class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        double maxDia = 0;
        for(int i= 0; i< dimensions.size(); i++) {
            auto len = dimensions[i][0];
            auto wid = dimensions[i][1];
            double diagonal = sqrt(len*len + wid*wid);
            //cout<<"diagonal: "<<diagonal<<" len: "<<len<<" wid: "<<wid<<" maxDia: "<<maxDia<<endl;
            if( diagonal > maxDia) {
                maxDia = diagonal;
                ans = len*wid;
            }
            else if(diagonal == maxDia) {
                ans = max(ans,len*wid);
            }

        }
        return ans;
    }
};
