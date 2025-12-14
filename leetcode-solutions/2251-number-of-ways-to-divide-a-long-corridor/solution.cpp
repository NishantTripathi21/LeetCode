class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9+7;
        long long ans = 1;
        int n = corridor.size();
        int cnt = 0;
        for(char ch: corridor) {
            if(ch == 'S')cnt++;
        }
        if( cnt&1 )return 0;
        int spaces = 0;
        vector<int>sp;
        bool pairF = 0;
        int index = 0;
        while( index < n && corridor[index] != 'S')index++;
        n--;
        while( n >= 0 && corridor[n] != 'S')n--;
        if(n <= 0 || index >= n)return 0;
        while(index < n) {
            char ch = corridor[index];
            if(ch== 'S') {
                index++;
                while(index < n) {
                    if(corridor[index] == 'S') {
                        index++;
                        break;
                    }
                    else index++;
                }
            }
            else {
                while(index < n && corridor[index] == 'P') {
                    index++;
                    spaces++;
                }
                sp.push_back(spaces);
                spaces = 0;
            } 
        }

        for(int i: sp) {
            ans = (ans * (i+1))%mod;
        }
        return ans;

    }
};
