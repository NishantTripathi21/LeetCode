class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        vector<int> counts;
        for (auto& pair : freq) {
            counts.push_back(pair.second);
        }

        sort(counts.rbegin(), counts.rend());

        int halfSize = arr.size() / 2;
        int removed = 0, setSize = 0;

        for (int count : counts) {
            removed += count;
            setSize++;
            if (removed >= halfSize) {
                return setSize;
            }
        }

        return setSize;
    }
};
