class MinStack {
public:

    MinStack(){
        stackData = new stack<int>;
        stackMin = new stack<int>;
    }

    void push(int x) {
        stackData->push(x);
        if (stackMin->size() == 0 || stackMin->top() > x)
            stackMin->push(x);
        else{
          stackMin->push(stackMin->top());
        } 
    }

    void pop() {
        if(stackData->size() > 0 && stackMin->size() > 0){
            stackMin->pop();
            stackData->pop();
        }else
            //throw exception("No element to pop");
            exit(1);
    }

    int top() {
        if (stackData->size() > 0 && stackMin->size() > 0)
            return stackData->top();
        else
            //throw exception("No element in stack");
            exit(1);
    }

    int getMin() {
        if (stackData->size() > 0 && stackMin->size() > 0)
            return stackMin->top();
        else
            //throw exception("No element in stack");
            exit(1);
    }
private:
    stack<int> *stackData;
    stack<int> *stackMin;
};
