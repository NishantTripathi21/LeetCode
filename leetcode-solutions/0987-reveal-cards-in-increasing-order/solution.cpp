class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int>ans(deck.size(),0);
        queue<int>q;
        for(int i=0;i<deck.size();i++){
            q.push(i);
        }
        int index=0;
        while(index < deck.size()){
            int temp=q.front();
            ans[temp]=deck[index];
            index++;
            q.pop();
            int temp2=q.front();
            q.pop();
            q.push(temp2);
        }
        return ans;
        
    }    
};
