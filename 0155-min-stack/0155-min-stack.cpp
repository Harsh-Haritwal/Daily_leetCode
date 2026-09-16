class MinStack {
public:
    stack<int>s1;
    stack<int>s2;
    int min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int value) {
        s1.push(value);
        if(value <= min){
            min = value;
            s2.push(value);
        }
        return;
    }
    
    void pop() {
        if(s1.empty()) return;
        int el = s1.top();
        if(!s2.empty() && s2.top() == el){
            s2.pop();
            if(s2.empty()) min = INT_MAX;
            else min = s2.top();
        }
        s1.pop();
        return;
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */