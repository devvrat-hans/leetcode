// Last updated: 3/27/2026, 5:27:05 PM
class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }

        output.push(x);

        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        int toPop = input.top();
        input.pop();

        return toPop;
    }
    
    int peek() {
        return input.top();
    }
    
    bool empty() {
        return input.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */