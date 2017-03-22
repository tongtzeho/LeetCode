class MyQueue {
public:
    /** Initialize your data structure here. */
    
    stack<int, vector<int>> s1, s2;
    
    MyQueue() {
         while (!s1.empty())
         {
             s1.pop();
         }
         while (!s2.empty())
         {
             s2.pop();
         }
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        int n;
        while (!s1.empty())
        {
            n = s1.top();
            s1.pop();
            s2.push(n);
        }
        s1.push(x);
        while (!s2.empty())
        {
            n = s2.top();
            s2.pop();
            s1.push(n);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int n = s1.top();
        s1.pop();
        return n;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
