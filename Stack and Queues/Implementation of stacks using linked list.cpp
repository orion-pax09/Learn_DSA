#include <iostream>
using namespace std;
class Node{
    public:
    Node*ptr;
    int data;
    Node(int val){
        data = val;
        ptr = nullptr;
    }
    Node(int val , Node*ptr1){
        data = val;
        ptr = ptr1;
    }
};
class stack{
    public:
    Node*topNode;
    stack(){
        topNode = nullptr;
    }
    void push(int val){
        Node*newNode = new Node (val);
        newNode->ptr = topNode;
        topNode = newNode;
    }
    void pop(){
        if (topNode!=nullptr){
            int val = topNode->data;
            Node*temp = topNode;
            topNode = topNode->ptr;
            delete temp;
        }
        else{
            cout << "Stack is empty"<<endl;
        }
    }
    int top(){
        if (topNode!=nullptr){
            return topNode->data;
        }
        else{
            return -1;
        }
    }
    bool isEmpty(){
        return topNode==nullptr;
    }
};
