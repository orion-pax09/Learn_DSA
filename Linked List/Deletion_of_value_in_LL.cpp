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
Node*Deletion_Of_value_in_LL(Node*head,int value){
    if (head==nullptr){
        return nullptr;
    }
    if (head->data == value){
        Node*temp = head;
        head = head->ptr;
        delete temp;
        return head;
    }
    Node*temp = head;
    Node*previous = nullptr;
    while(temp!=nullptr){
        if (temp->data ==value){
            previous->ptr = temp->ptr;
            delete temp;
            break;
        }
        previous = temp;
        temp = temp->ptr;
    }
        return head;
}
int main(){
    vector<int>ARR = {33,44,55,66,77};
    Node*node = convertarr2ll(ARR);
    node = Deletion_Of_value_in_LL(node , 55);
    traversalLL(node);
}
