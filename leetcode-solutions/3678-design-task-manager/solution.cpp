class TaskManager {
public:
    unordered_map<int,int>taskToUser;
    unordered_map<int,int>taskToPriority;
    set<pair<int,int>>taskAndPriority;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i= 0;  i< tasks.size(); i++) {
            int user = tasks[i][0];
            int task = tasks[i][1];
            int priority = tasks[i][2];
            taskToUser[task] = user;
            taskToPriority[task] = priority;
            taskAndPriority.insert({priority,task});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        int user = userId;
        int task = taskId;
        taskToUser[task] = user;
        taskToPriority[task] = priority;
        taskAndPriority.insert({priority,task});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPrio = taskToPriority[taskId];
        taskAndPriority.erase({oldPrio,taskId});
        taskAndPriority.insert({newPriority,taskId});
        taskToPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int prio = taskToPriority[taskId];
        taskAndPriority.erase({prio,taskId});
        taskToUser.erase(taskId);
    }
    
    int execTop() {
        if(taskAndPriority.empty())return -1;
        auto highest = *(taskAndPriority.rbegin());
        int taskId =  highest.second;
        taskAndPriority.erase(highest);
        return taskToUser[taskId];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
