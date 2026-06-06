class MinStack {
public:
    // stack<pair<int,int>> s;  // {val,minVal}
    stack<long long >s;
    long long int minVal;
    MinStack() {
        
    }
    
    void push(int val) {
        // if(s.empty()){
        //     s.push({val,val});
        // }
        // else{
        //     int minVal = min(val, s.top().second);
        //     s.push({val,minVal});
        // }
        /////******////MORE OPTIMAL 
        if(s.empty()){
            s.push(val);
            minVal = val;
        }else{
            if(val<minVal){
                s.push((long long ) 2* val - minVal);
                minVal = val;
            }else{
                s.push(val);
            }
            
        }

    }
    
    void pop() {
        // s.pop(); 

        if(s.top()<minVal){
            minVal = 2 * minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        // return s.top().first;
        if(s.top()< minVal){
            return minVal;
        }else{
            return s.top();
        }
        
    }
    
    int getMin() {
        // return s.top().second;
        return minVal;
        
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
