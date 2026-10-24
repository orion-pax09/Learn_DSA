#include <iostream>
using namespace std;
class QueueNode{
    public:
    QueueNode*ptr;
    int data;
    QueueNode(int x){
        data = x;
        ptr = nullptr;
    }
};

class queue{
    public:
    QueueNode*front;
    QueueNode*rear;
    queue(){
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int x){
        QueueNode*node = new QueueNode (x);
        if (front==nullptr){
            rear = node;
            front = node;
            rear->ptr = front;
        }
        else{
        rear->ptr = node;
        rear = node;
        rear->ptr = front;
        }

    }
    void dequeue(){
        if (front==nullptr){
            cout << "Queue is empty"<<endl;
        }
        QueueNode*temp = front;
        front = front->ptr;
        delete temp;
        rear->ptr = front;
    }
    void top(){
        if (front == nullptr){
            cout << "Queue is empty"<<endl;
        }
        cout << front->data<<endl;
    }
    int IsEmpty(){
        return front==nullptr;
    }
};

int main(){
    queue Q;
    Q.enqueue(80);
    Q.top();
    Q.enqueue(70);
    Q.enqueue(20);
    Q.dequeue();
    Q.top();
    cout << Q.IsEmpty()<<endl;
    Q.dequeue();
    Q.dequeue();
    cout << Q.IsEmpty();
}
