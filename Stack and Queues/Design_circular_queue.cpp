class MyCircularQueue {
public:
int*arr;
int front;
int rear;
int curr_size;
int size;
    MyCircularQueue(int k) {
        size = k;
        arr = new int [k];
        front = -1;
        rear = -1;
        curr_size = 0;
    }
    
    bool enQueue(int value) {
        if (curr_size ==size){
            return false;
        }
        else if (curr_size == 0){
            front=0;
            rear = 0;
        }
        else{
            rear=(rear+1)%size;
        }
        arr[rear]=value;
        curr_size++;
        return true;
    }
    
    bool deQueue() {
        if(curr_size == 0){
            return false;
        }
        int v = arr[front];
        if (curr_size == 1){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%size;
        }
        curr_size--;
        return true;
    }
    
    int Front() {
        if (curr_size == 0){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if (curr_size == 0){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return curr_size == 0;
    }
    
    bool isFull() {
        return curr_size==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
