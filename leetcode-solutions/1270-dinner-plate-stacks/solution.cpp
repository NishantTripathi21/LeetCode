class DinnerPlates {
public:
    int capacity;
    vector<stack<int>> stacks;
    set<int> available; //index of stacks with available space

    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        if (available.empty() || *available.begin() >= stacks.size()) {
            stacks.push_back(stack<int>());
            available.insert(stacks.size() - 1);
        }
        int index = *available.begin();
        stacks[index].push(val);
        if (stacks[index].size() == capacity) {
            available.erase(index); 
        }
    }

    int pop() {
        while (!stacks.empty() && stacks.back().empty()) {
            stacks.pop_back();
        }
        if (stacks.empty()) {
            return -1; 
        }
        int val = stacks.back().top();
        stacks.back().pop();
        available.insert(stacks.size() - 1);
        return val;
    }

    int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks[index].empty()) {
            return -1; 
        }
        int val = stacks[index].top();
        stacks[index].pop();
        available.insert(index); 
        return val;
    }
};

