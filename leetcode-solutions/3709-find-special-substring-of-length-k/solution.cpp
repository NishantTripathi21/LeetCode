class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        if (k > n) return false;
    
        int count = 1;
        //unordered_map<char,int>st;
        int left = 0;
        int right = 0;
        bool result = false;
        while( right < n) {
            //char ch = s[right];
            if( right >= 1 && s[right] == s[right-1]){
                count++;
            }
            else{
                left = right;
                count = 1;
            }
            if(count == k) {
                    bool ans1 = true;
                    if ((left - 1 >= 0 && s[left - 1] == s[left])) {
                        ans1 =false;
                    }
                    bool ans2 = true;
                    if( (right + 1 < n && s[right + 1] == s[right]) ) {
                        ans2 = false;
                    }
                    
                    
                    if( ans1 && ans2){
                         result = true;   
                    }
            }
            // if( right-  left +1 >= k){
            //     st[s[left]]--;
            //     if(st[s[left]] == 0){
            //         st.erase(s[left]);
            //     }
            //     left++;
            // }
            //cout<<" st.size "<<st.size()<<" "<<"right: "<<right<<" left: "<<left;
            right++;
        }
        
        return result;
    }
};
