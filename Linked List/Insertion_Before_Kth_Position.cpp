#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node*ptr;
    Node*back;
    Node(int data1){
        data = data1;
        ptr = nullptr;
        back = nullptr;
    }
    Node(int data1 , Node*ptr1 , Node*back1){
        data=data1;
        ptr = ptr1;
        back = back1;
    }
};
Node*Traversalarray(vector<int>&arr){
    Node*head = new Node(arr[0]);
    Node*previous = head;
    for (int i = 1 ; i < arr.size()  ; i ++){
        Node*temp = new Node(arr[i] , nullptr , previous);
        previous->ptr = temp;
        previous = temp;
    }
    return head;
}
void print(Node*head){
    Node*HEAD = head;
    while(HEAD!=nullptr){
        cout << HEAD->data << " ";
        HEAD = HEAD->ptr;
    }
}

Node*InsertionbeforeHEAD(Node*head , int val){
    Node*newNode = new Node (val , head , nullptr);
    head->back = newNode;
    return newNode;
}

Node*InsertionBeforeTail(Node*head , int val){
    if (head->ptr==nullptr){
        return InsertionbeforeHEAD(head , val);
    }
    Node*temp = head;
    while(temp->ptr!=nullptr){
        temp = temp->ptr;
    }
    Node*previous = temp->back;
    Node*newNode = new Node(val , temp , previous);
    previous->ptr = newNode;
    temp->back = newNode;
    return head;
}

Node*Insertion_before_KthPosition(Node*head , int k , int val){
    if (k==1){
        return InsertionbeforeHEAD(head , val);
    }
    int cnt = 0;
    Node*temp = head;
    while(temp!=nullptr){
        cnt++;
        if (cnt == k){
            break;
        }
        temp = temp->ptr;
    }
    Node*previous = temp->back;
    Node*newNode = new Node (val , temp , previous);
    previous->ptr = newNode;
    temp->back = newNode;
    return head;
}
int main(){
    vector<int>ARR={33,44,55,66,77,88,99};
    Node*temp = Traversalarray(ARR);
    Node*node = Insertion_before_KthPosition(temp , 3 , 343);
    print(node);
}
