class Solution {
public:
    int method1( string& customers){
        // using PreFix sum 
        // tc- 0(N) + 0(N)
        // SC- 0(N);
        vector<int>rightOpen( customers.size(),0); // to store how many shop are open to right of a particular index
        int rightCust = 0;
        for( int i = customers.size()-1; i>= 0;i--){
            if( customers[i] == 'Y'){
                rightCust++;
            }
            rightOpen[i] = rightCust;
        }

        int leftClosed = 0; // to store shops closed to the left of a index
        int penality = 0; // if we close shop at any index, penality is leftClosed shops plus rightOpen shops
        int minPenality = INT_MAX;
        int ans = 0; //earliest time to  close
        for( int i= 0; i< customers.size() ;i++){
            penality = leftClosed + rightOpen[i];
            if( penality < minPenality){
                ans = i;
                minPenality = penality ;
            }
            if( customers[i] == 'N'){
                leftClosed++;
            }
        }
        // for index = customer.size() if shop closes after end of string
        if( minPenality > leftClosed){
            ans = customers.size();
        }

        return ans;

    }
    int bestClosingTime(string customers) {
        return method1(customers);
    }
};
