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
    bool isEmpty(){
        return front==nullptr;
    }
    void enqueue(int x){
        QueueNode*node = new QueueNode (x);
        if (isEmpty()){
            front = node;
            rear = node;
        }
        rear->ptr = node;
        rear = node;
    }
    void deuque(){
        if (isEmpty()){
            cout << "Queue is empty"<<endl;
            return;
        }
        QueueNode*temp = front;
        if (front == rear){
            delete front;
            front = nullptr;
            rear = nullptr;
            return;
        }
        front = front->ptr;
        temp->ptr = nullptr;
        delete temp;
    }
    void top(){
        if (front==nullptr){
            cout << "Queue is empty"<<endl;
            return;
        }
        cout << front->data<<endl;
    }
};

int main(){
    queue Q;
    Q.enqueue(80);
    Q.top();
    Q.enqueue(70);
    Q.enqueue(20);
    Q.deuque();
    Q.top();
    cout << Q.isEmpty()<<endl;
    Q.deuque();
    Q.deuque();
    cout << Q.isEmpty();
}
