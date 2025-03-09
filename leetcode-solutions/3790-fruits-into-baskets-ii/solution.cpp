class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        // sort(fruits.begin(),fruits.end());
        // sort(baskets.begin(),baskets.end());
        
        vector<int>placed(n,0);
        int cnt = 0;
        
        for(int i= 0; i< n; i++) {
            bool plsd = false;
            for(int j = 0; j<n; j++) {
                if(fruits[i] <= baskets[j] && placed[j] == false) {
                    placed[j] = true;
                    plsd = true;
                    break;
                }
            }
            if(!plsd)cnt++;
        }
        
        return cnt;
    }
};
