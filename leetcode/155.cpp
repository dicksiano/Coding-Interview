class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(mini.empty() || x < mini.top())  mini.push(x);
        else mini.push(mini.top());
    }
    
    void pop() {
        s.pop();
        mini.pop();
    }
    
    int top() {        
        return s.top();
    }
    
    int getMin() {
        return mini.top();
    }
    
private:
    stack<int> s, mini;
};
