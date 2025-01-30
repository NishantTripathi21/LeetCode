class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // expireDay->numberOfApples
        int maxApplesEaten = 0;
        int currDay = 0;
        while (currDay < n || !minHeap.empty()) {
            while (!minHeap.empty() && minHeap.top().first <= currDay) {
                minHeap.pop();
            }

            if (currDay < n && apples[currDay] > 0) {
                minHeap.push({currDay + days[currDay], apples[currDay]});
            }

            if (!minHeap.empty()) {
                auto top = minHeap.top();
                minHeap.pop();
                if (top.second > 1) {
                    minHeap.push({top.first,top.second-1});
                }
                maxApplesEaten++;
            }

            currDay++;
        }

        return maxApplesEaten;
    }
};
