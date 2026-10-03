class MinStack {
public:
   long long mini;
   stack<long long >st;

    MinStack() {
        mini=LLONG_MAX;        
    }
    
    void push(int value) {
        long long x=(long long)value;
        if(st.size()==0){
            st.push(x);
            mini=x;
        }
        else if(x>=mini) st.push(x);
        else{
            long long old=2*x-mini;
            st.push(old);
            mini=x;

            } 
        
    }
    
    void pop() {
        if(st.top()<mini){
            long long y=2*mini-st.top();
            mini=y;
            st.pop();
        }
        else st.pop();        
    }
    
    int top() {
         if (st.top() < mini)
            return (int)mini;

        return (int)st.top();
        
    }
    
    int getMin() {
        return (int)mini;        
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