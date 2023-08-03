class MinStack {
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        s.push(val);
        min_stack.push(min(val, min_stack.top()));
    }
    
    void pop() {
        min_stack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private:
    stack<int> s;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */