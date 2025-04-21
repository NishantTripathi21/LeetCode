class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long maxi = 0;
        long long sum = 0;
        long long mini = 0;
        for (int i = 0; i < n; i++) {
            sum += differences[i];
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }
        //cout<<" lower: "<<mini<<" maxi: "<<maxi<<endl;
        int subsquences = 0;
        for(int i= lower; i<= upper; i++) {
            //cout<<" i "<<i<<endl;
            if( mini + i >= lower && maxi + i <= upper) {
                subsquences = upper - (maxi + i) + 1;
                break;
            }
        }
        return subsquences;
    }
};
