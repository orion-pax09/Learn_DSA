 class ArrayQueue {
public:
int front = 0;
int rear = 0;
int curr_size;
static const int size=10;
int Q[size];

    ArrayQueue() {
        front=-1;
        rear=-1;
        curr_size=0;
    }
    
    void push(int x) {
        if (curr_size==size){
            cout << "Queue is full";
        }
        else if (curr_size==0){
            front=0;
            rear=0;
        }
        else{
            rear = (rear+1) % size;
        }
        Q[rear]=x;
        curr_size++;
    }
    
    int pop() {
        if (curr_size==0){
            cout << "Queue is empty";
            return -1;
        }
        int value = Q[front];
        if (curr_size==1){
            front=-1;
            rear=-1;
        }
        else{
            front = (front+1)%size;
        }
        curr_size--;
        return value;
    }
    
    int peek() {
        if (curr_size==0){
            return -1;
        }
        return Q[front];
    }
    
    bool isEmpty() {
        return curr_size==0;
    }
};
