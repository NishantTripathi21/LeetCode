class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int>circle(2*n);
        for(int i= 0; i< 2*n; i++) {
            int ele = colors[i%n];
            circle[i] = ele;
        }
        int count = 0;
        //for(auto i: circle)cout<<i;

        int right = 1;
        int left = 0;
        while( right < colors.size()+k && left < colors.size()) {
            if(circle[right] == circle[right-1]) { 
                left= right;
                right = right+1;
                continue;
            }

            //cout<<" left: "<<left<<" right: "<<right<<" cnt: "<<count<<endl;
            if (left >= colors.size()) {
                //cout << "Breaking loop: left exceeded colors size\n";
                break;
            }

            if(right-left+1 == k && left < n) {
                count++;
                left++;
            }
            right++;
        }
        return count;
    }

};
