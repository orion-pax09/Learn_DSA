#include <iostream>
using namespace std;
#include <vector>
class Node{
    public:
    int data;
    Node*ptr;
    Node(int data1){
        ptr = nullptr;
        data=data1;
    }
    Node(int data1 , Node*Ptr){
        data = data1;
        ptr = Ptr;
    }
};
Node*convertarr2ll(vector<int>&arr){
    Node*head = new Node (arr[0]);
    Node*movers = head;
    for (int i = 1 ; i < arr.size() ; i++){
        Node*temp = new Node (arr[i]);
        movers->ptr = temp; 
        movers = temp;
    }
    return head;
}
void traversalLL(Node*head){
    Node*temp = head;
    while(temp!=nullptr){
        cout << temp->data<<" ";
        temp = temp->ptr;
    }
}
Node*deletion_of_tail(Node*head){
    if (head==nullptr||head->ptr==nullptr){
        return nullptr;
    }
    Node*temp = head;
    while(temp->ptr->ptr!=nullptr){
        temp = temp->ptr;
    }
    delete temp->ptr;
    temp->ptr = nullptr;
    return head;
}
int main(){
    vector<int>ARR = {33,44,55,66,77};
    Node*node = convertarr2ll(ARR);
    node = deletion_of_tail(node);
    traversalLL(node);
}
