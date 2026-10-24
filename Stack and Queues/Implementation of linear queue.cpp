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
        front =-1;
        rear = -1;
        size = n;
        arr = new int [size];
    }
    void enqueue(int x){
        if (rear == size-1){
            cout << "Queue overflow"<<endl;
            return;
        }
        if (front== -1){
            front= 0;
        }
        rear++;
        arr[rear] = x;
    }
    void dequeue(){
        if (front == -1){
            cout << "Queue underflow"<<endl;
            return;
        }
        if (front == rear){
            front =-1;
            rear = -1;
        }
        else{
            front++;
        }
    }
    int top(){
        if (front == -1 && rear == -1){
            return -1;
        }
        return arr[front];
    }
    void display(){
        for (int i = front ; i <= rear ; i++){
            cout << arr[i];
        }
        cout << endl;
    }
};
int main(){
    Queue Q(10);
    Q.enqueue(66);
    cout << Q.top()<<endl;
    Q.enqueue(99);
    Q.enqueue(55);
    cout <<Q.top()<<endl;
    Q.dequeue();
    cout << Q.top();
}
