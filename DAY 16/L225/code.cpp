class MyStack 
{
    private:
    queue<int> q1;
    public:
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) 
    {
        q1.push(x);    
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int len = q1.size();
        for(int i = 0; i < len - 1; i++) {
            int tmp = q1.front();
            q1.pop();
            q1.push(tmp);
        }
        int res = q1.front();
        q1.pop();

        return res;
    }

    /** Get the top element. */
    int top() {
        return q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return !q1.size()?true:false;
    }
};
