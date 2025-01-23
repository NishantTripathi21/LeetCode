class Solution {
public:
    bool canCompleteTasks(int k, const vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> taskQueue(tasks.begin(), tasks.begin() + k);
        multiset<int> workerSet(workers.end() - k, workers.end());

        while (!taskQueue.empty()) {
            int tsk = *taskQueue.begin(); // Smallest task requirement
            auto wrkIt = workerSet.begin(); // Smallest worker strength

            if (*wrkIt >= tsk) {
                // Worker can handle the task without a pill
                workerSet.erase(wrkIt);
                taskQueue.erase(taskQueue.begin());
            } else {
                // Worker cannot handle the task without a pill
                if (pills <= 0) return false;

                int newWrk = *wrkIt + strength; // Increase worker's strength using a pill
                pills--;

                // Check if the new worker strength can handle any task
                auto possibleTask = taskQueue.upper_bound(newWrk);
                if (possibleTask == taskQueue.begin()) return false;

                // Assign the task that can be handled by the worker
                possibleTask--;
                taskQueue.erase(possibleTask);
                workerSet.erase(wrkIt);
            }
        }
        return true;
    }

    int method(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0, right = min(tasks.size(), workers.size()), result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCompleteTasks(mid, tasks, workers, pills, strength)) {
                result = mid;
                left = mid + 1; // Try to complete more tasks
            }
            else {
                right = mid - 1; // Try fewer tasks
            }
        }

        return result;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        return method(tasks,workers,pills,strength);
    }
};
