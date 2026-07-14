class ArrayStack {
public:
int stack[10];
int topindex;
    ArrayStack() {
        topindex = -1;
    }
    
    void push(int x) {
        if (topindex < 9){
            topindex +=1;
            stack[topindex]=x;
        }
    }
    
    int pop() {
        if (topindex==-1){
            return -1;
        }
        int value = stack[topindex];
        topindex -=1;
        return value;
    }
    
    int top() {
        if (topindex==-1){
            return -1;
        }
        return stack[topindex];
    }
    
    bool isEmpty() {
        return topindex==-1;
    }
};
