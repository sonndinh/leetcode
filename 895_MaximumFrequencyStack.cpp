class FreqStack {
private:
    // Data for O(1) time solution.
    vector<stack<int>> stacks;
    unordered_map<int, int> occur_counts;
    
    // Data for O(lgn) time solution
    struct Compare {
        bool operator() (const tuple<int,int,int>& a, const tuple<int,int,int>& b) const {
            if (get<1>(a) < get<1>(b))
                return true;
            if (get<1>(a) > get<1>(b))
                return false;
            if (get<2>(a) < get<2>(b))
                return true;
            return false;
        }
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> queue;
    int position = 0;
    
public:
    FreqStack() {
        
    }
    
    // O(lgn) time.
    void push(int x) {
        int freq = 1;
        if (occur_counts.find(x) != occur_counts.cend())
            freq = occur_counts[x] + 1;
        ++occur_counts[x];
        queue.push({x, freq, ++position});
    }
    
    // O(lgn) time.
    int pop() {
        auto tpl = queue.top();
        queue.pop();
        int val = get<0> (tpl);
        --occur_counts[val];
        return val;
    }
    
    // O(1) time.
    void push1(int x) {
        ++occur_counts[x];
        if (stacks.size() < occur_counts[x]) {
            stack<int> temp;
            temp.push(x);
            stacks.push_back(temp);
        } else {
            stacks[occur_counts[x] - 1].push(x);
        }
    }
    
    // O(1) time.
    int pop1() {
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
