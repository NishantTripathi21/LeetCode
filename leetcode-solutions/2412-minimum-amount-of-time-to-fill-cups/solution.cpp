class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> maxHeap;
        for (int a : amount) {
            if (a > 0) maxHeap.push(a);
        }

        int seconds = 0;
        while (!maxHeap.empty()) {
            int first = maxHeap.top(); maxHeap.pop();
            if (maxHeap.empty()) {
                seconds += first;
                break;
            }
            int second = maxHeap.top(); maxHeap.pop();
            first--, second--, seconds++;
            if (first > 0) maxHeap.push(first);
            if (second > 0) maxHeap.push(second);
        }

        return seconds;
    }
};
