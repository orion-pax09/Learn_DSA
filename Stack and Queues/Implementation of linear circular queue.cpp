#include <iostream>
using namespace std;
class Queue{
    public:
    int*arr;
    int front;
    int rear;
    int size;
    int capacity;
    Queue(int n){
        front = 0;
        rear = -1;
        capacity = n;
        size = 0;
        arr = new int [capacity];
    }
    void enqueue(int x){
        if (size >= capacity){
            cout << "Overflow"<<endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }
    void deqeue(){
        if (size == 0){
            cout << "queue is empty"<<endl;
            return;
        }
        front = (front+1)%capacity;
        size--;
    }
    void top(){
        if (size==0){
            cout << "Queue is empty"<<endl;
            return;
        }
        int x = arr[front];
        cout << x<<endl;
    }
    bool isempty(){
        return size==0;
    }
};
int main(){
    Queue q(10);
    q.enqueue(40);
    q.enqueue(80);
    q.enqueue(60);
    q.top();
    q.deqeue();
    q.top();
    cout << q.isempty()<<endl;
    q.deqeue();
    q.deqeue();
    q.top();
    cout << q.isempty();
}
