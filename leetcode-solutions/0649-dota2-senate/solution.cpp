class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant_queue, dire_queue;
        int n = senate.size();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant_queue.push(i);
            } 
            else {
                dire_queue.push(i);
            }
        }
        while (!radiant_queue.empty() && !dire_queue.empty()) {
            int r_index = radiant_queue.front();
            int d_index = dire_queue.front();

            radiant_queue.pop();
            dire_queue.pop();

            if (r_index < d_index) {
                radiant_queue.push(r_index + n);
            } else {
                dire_queue.push(d_index + n);
            }
        }

        return radiant_queue.empty() ? "Dire" : "Radiant";

    }
};
