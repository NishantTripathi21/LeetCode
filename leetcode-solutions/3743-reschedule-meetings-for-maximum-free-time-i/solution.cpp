class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>sum;
        for( int i= 0; i< startTime.size();i++) {
            if (i == 0) {
                sum.push_back(startTime[i]);
            }
            else {
                sum.push_back(startTime[i] - endTime[i - 1]);
               // cout<<sum.back()<<endl;
            }
        }
        sum.push_back(eventTime-endTime[endTime.size()-1]);
        //for( int i:sum)cout<<i<<" ";
        //for(int i:sum)cout<<i<<" ";
        // sum of k+1 elements;
        int size = sum.size();
        int left =  0;
        int right = 0;
        int maxTime = 0;
        int s = 0;
        while( right < size) {
            s += sum[right];
    
            if (right - left + 1 > k + 1) {
                s -= sum[left];
                left++;
            }
    
            if (right - left + 1 == k + 1) {  
                maxTime = max(maxTime, s);
            }
    
            right++;
        }
        return maxTime;
    }
};
