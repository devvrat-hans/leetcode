// Last updated: 3/27/2026, 5:27:06 PM
class MyStack {
private:
    queue<int> q;
    
public:
    MyStack() {
    }
    
    void push(int x) {
        int currSize = q.size();
        q.push(x);

        while(currSize--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int toPop = q.front();
        q.pop();

        return toPop;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */