class MinStack {
public:
    stack<long long>st;
    long long min;
    MinStack() {
        min=LLONG_MAX;
    }
    void push(int val) {
        long long x=(long long)val;
        if(st.size()==0){
            st.push(x);
            min=x;
        }
        else if(val>=min) st.push(val);
        else{
            st.push(x+(x-min));
            min=x;
        }
    }
    
    void pop() {
        if(st.top()<min){
            int oldmin=2*min-st.top();
            min=oldmin;
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<min){
            return (int)min;
        }
        else return (int)st.top();
    }
    
    int getMin() {
        return min;
    }
};
