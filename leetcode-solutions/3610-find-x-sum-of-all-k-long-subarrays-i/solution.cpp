class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> freq;

            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            vector<pair<int, int>> temp;
            for (auto &p : freq) {
                temp.push_back({p.second, p.first});
            }

            sort(temp.begin(), temp.end(), [](auto &a, auto &b) {
                if (a.first == b.first) return a.second > b.second;
                return a.first > b.first;
            });

            long long sum = 0;
            int count = 0;
            for (auto &p : temp) {
                if (count == x) break;
                sum += 1LL * p.first * p.second;
                count++;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
