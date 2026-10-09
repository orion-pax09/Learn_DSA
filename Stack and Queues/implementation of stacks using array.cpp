class stack{
    public:
    double*Array;
    int size;
    int top;
    stack(int size){
        this->size = size;
        Array = new double [size];
        top = 0;
    }
    void push(int x){
        if (top < size){
            Array[top] = x;
            top++;
        }
        else{
            cout << "stack is full"<<endl;
        }
    }
    double pop(){
        if (top > 0){
            top--;
            return Array[top-1];
        }
        else{
            return -1;
        }
    }
    void peek(){
        if (top > 0){
            cout <<  Array[top-1]<<endl;
        }
        else{
            cout << "stack is empty"<<endl;
        }
    }
    bool IsEmpty(){
        return top == -1;
    }
};
