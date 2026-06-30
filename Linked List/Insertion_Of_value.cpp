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

Node*Insertion_Of_value(Node*head , int value , int k){
    if (head ==nullptr){
        return new Node (value);
    }
    if (k==1){
        return new Node (value);
    }
    Node* temp = head;
    int count = 1;
    while (temp!=nullptr){
        count++;
        if (temp->data == value){
            Node*newnode = new Node (value);
            newnode->ptr = temp->ptr;
            temp->ptr = newnode;
            break;
        }
        temp = temp->ptr;
    }
    return head;
}


int main(){
    vector<int>ARR = {33,44,55,66,77};
    Node*node = convertarr2ll(ARR);
    node = Insertion_Of_value(node , 77, 4);
    traversalLL(node);
}
