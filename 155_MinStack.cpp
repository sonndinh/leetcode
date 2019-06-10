class MinStack {
private:
    // Each pair contains current element and minimum value of all elements from 
    // bottom of the stack to the current element.
    list<pair<int, int>> data;
    
public:
    /** initialize your data structure here. */
    MinStack() : data{} {
    }
    
    void push(int x) {
        if (data.empty()) {
            data.emplace_back(x, x);
        } else {
            if (x < data.back().second)
                data.emplace_back(x, x);
            else 
                data.emplace_back(x, data.back().second);
        }
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        return data.back().first;
    }
    
    int getMin() {
        return data.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
