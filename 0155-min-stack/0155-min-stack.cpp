class MinStack {
    stack<int> st;// stores normal values, accd to the quest 
    stack<int> minm;// stores all the minm values we come across
public:
    MinStack() {
        // clear both stacks
        st=stack<int>();
        minm=stack<int>();
    }
    
    void push(int val) {
        if(minm.empty() || val<=minm.top()){
            minm.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top()==minm.top()){
            // top wala element hi current minm hai, pop karo dono ko
            minm.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();    
    }
    
    int getMin() {
        return minm.top();
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