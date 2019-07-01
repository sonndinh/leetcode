class FreqStack {
private:
    vector<stack<int>> stacks;
    unordered_map<int, int> occur_counts;
    
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        ++occur_counts[x];
        if (stacks.size() < occur_counts[x]) {
            stack<int> temp;
            temp.push(x);
            stacks.push_back(temp);
        } else {
            stacks[occur_counts[x] - 1].push(x);
        }
    }
    
    int pop() {
        int val = stacks.back().top();
        stacks.back().pop();
        if (stacks.back().empty())
            stacks.pop_back();
        
        --occur_counts[val];
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
