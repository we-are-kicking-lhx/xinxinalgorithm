class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        num_min.push(INT_MAX);
    }
    
    void push(int x) {
        num.push(x);
        num_min.push(min(num_min.top(),x));
    }
    
    void pop() {
        num.pop();
        num_min.pop();
    }
    
    int top() {
        return num.top();
    }
    
    int getMin() {
        return num_min.top();
    }
private:
    stack<int> num,num_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */