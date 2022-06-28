class MinStack {
public:
    long long minValue;
    long long* stk;
    int itr;
    MinStack() {
        minValue = INT_MAX;
        stk = new long long[30001];
        itr = -1;
    }
    
    void push(int val) {
        if(itr == -1){
            itr++;
            stk[itr] = val;
            minValue = val;
        }
        else {
            if(val > minValue){
                itr++;
                stk[itr] = val;
            }
            else {
                itr++;
                stk[itr] = 2ll * val - minValue;
                minValue = val;
            }
        }
    }
    
    void pop() {
        if(minValue > stk[itr]){
            minValue = 2 * minValue - stk[itr];
        }
        itr--;
    }
    
    int top() {
        if(minValue < stk[itr]){
            return stk[itr];
        }
        else {
            int currentMin = 2 * minValue - stk[itr];
            return (stk[itr] + currentMin) / 2;
        }
    }
    
    int getMin() {
        return minValue;
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