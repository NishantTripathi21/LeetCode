class Solution {
public:
// method 2 by RE
    void maxprofitRE(vector<int>& prices,int i, int &maxProfit, int &minPrice){
        // base case
        if(i==prices.size())return ;
        //one sol
         if(prices[i]<minPrice){
            minPrice=prices[i];
            }
         maxProfit=max(maxProfit,prices[i]-minPrice);


         //RC
         maxprofitRE(prices,i+1,maxProfit,minPrice);

    }
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minprice=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minprice){
                minprice=prices[i];
            }
            else{
                ans=max(ans,prices[i]-minprice);
            }
            
        }
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;
        maxprofitRE(prices,0,maxProfit,minPrice);    
        return maxProfit;   
    }
};
