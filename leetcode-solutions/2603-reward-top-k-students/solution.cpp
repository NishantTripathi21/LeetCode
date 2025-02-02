class Solution {
public:
    struct compare{
        bool operator()( pair<long long, long long> a, pair<long long, long long> b) {
            if( a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> posSet(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negSet(negative_feedback.begin(), negative_feedback.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        int n = report.size();
        for (int i = 0; i < n; ++i) {
            int id = student_id[i], score = 0;
            stringstream ss(report[i]);
            string word;
            while (ss >> word) {
                if (posSet.count(word)) score += 3;
                else if (negSet.count(word)) score -= 1;
            }
            pq.push({score, id});
            if (pq.size() > k) pq.pop(); 
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; --i) {
            result[i] = pq.top().second;
            pq.pop();
        }
        
        return result;
    }
};
