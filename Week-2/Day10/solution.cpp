class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> myStack;
    stack<int> minStack;
    
    MinStack() {
    }
    
    void push(int x) {
        if( myStack.empty() ) {
            myStack.push(x);
            minStack.push(x);
            return;
        }
        if( x <= minStack.top() ) {
            minStack.push(x);
        }
        myStack.push(x);
    }
    
    void pop() {
        if( myStack.empty() ) return;
        if( myStack.top() == minStack.top() ) {
            minStack.pop();
        }
        myStack.pop();
    }
    
    int top() {
        if( myStack.empty() ) return -1;
        return myStack.top();
    }
    
    int getMin() {
        if( minStack.empty() ) return -1;
        return minStack.top();
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