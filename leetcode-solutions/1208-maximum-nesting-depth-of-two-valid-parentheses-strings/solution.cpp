class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> answer(seq.length());
        int depth = 0; 

        for (int i = 0; i < seq.length(); ++i) {
            if (seq[i] == '(') {
                ++depth;
                answer[i] = depth % 2;
            } 
            else {
                answer[i] = depth % 2;
                --depth; 
            }
        }
        return answer;
    }
};
