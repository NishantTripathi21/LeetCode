class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        heights.push_back(0);
        std::stack<int> s;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = std::max(maxArea, h * w);
            }
            s.push(i);
        }
        heights.pop_back();
        return maxArea;
    }
};
