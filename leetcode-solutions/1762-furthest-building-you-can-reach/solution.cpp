class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        
        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            
            if (diff > 0) { 
                minHeap.push(diff);
                // initially use all ladders and when u cant ladder anymore,start
                // replacing shortest difference from bricks 
                if (minHeap.size() > ladders) { // size of heap represents ladder used
                    bricks -= minHeap.top(); // when size exceeds maximum ladder, start using bricks
                    minHeap.pop();  // Remove this brick expense from the heap
                }
                
                if (bricks < 0) return i;
            }
        }
        return heights.size() - 1;
    }
};
