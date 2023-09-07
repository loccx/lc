class MinStack {
private:
    vector<int> stack;
    vector<int> min;

int minItem;
public:
    MinStack() {}
    
    void push(int val) {
        if (min.empty() || val <= getMin()) {
            min.push_back(val);
        }
        stack.push_back(val);
    }
    
    void pop() {
        if (stack.back() == min.back()) min.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
