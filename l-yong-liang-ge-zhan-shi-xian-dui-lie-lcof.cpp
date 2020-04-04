class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stack2.push(value);
        size++;
    }
    
    int deleteHead() {
        if(size==0) return -1;
        if(stack1.empty()){
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        int ans=stack1.top();
        stack1.pop();
        size--;
        return ans;
    }
private:
    stack<int> stack1,stack2;
    int size=0;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */