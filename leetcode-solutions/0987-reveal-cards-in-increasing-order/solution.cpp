class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int>q;
        vector<int>ans(deck.size());
        //put indixes of ans in q;
        for(int i=0;i<ans.size();i++){
            q.push(i);
        }
        //reverse simulation +filling using sorted deck
        for(int i=0;i<deck.size();i++){
            //reveal
            ans[q.front()]=deck[i];
            q.pop();
            //push front to bottom
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }    
};
