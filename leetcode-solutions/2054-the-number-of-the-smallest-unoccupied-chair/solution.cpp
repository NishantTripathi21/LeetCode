class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<vector<int>> sortedTime;
        
        for (int i = 0; i < n; i++) {
            sortedTime.push_back({times[i][0], times[i][1], i});
        }
        
        sort(sortedTime.begin(), sortedTime.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap; // Stores available chair numbers
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap2; // Stores {freeTime, chairNumber}

        for (int i = 0; i < n; i++) {
            minHeap.push(i);
        }

        for (int index = 0; index < sortedTime.size(); index++) {
            int arriveTime = sortedTime[index][0];
            int leaveTime = sortedTime[index][1];
            int friendNumber = sortedTime[index][2];

            // Free chairs that are now available
            while (!minHeap2.empty() && minHeap2.top().first <= arriveTime) {
                int freeChair = minHeap2.top().second;
                minHeap2.pop();
                minHeap.push(freeChair);
            }

            // Allocate a new empty chair
            int chair = minHeap.top();
            minHeap.pop();

            if (friendNumber == targetFriend) return chair;
            minHeap2.push({leaveTime, chair});
        }

        return -1;
    }
};
