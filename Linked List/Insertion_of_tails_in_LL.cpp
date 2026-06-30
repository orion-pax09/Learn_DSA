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

Node*Insertion_of_tail_In_LL(Node*head , int value){
    if (head==nullptr){
        return new Node (value);
    }

    Node*temp = head;
    while (temp->ptr != nullptr){
        temp = temp->ptr;    
    }
    temp->ptr = new Node (value);
    return head;
}

int main(){
    vector<int>ARR = {33,44,55,66,77};
    Node*node = convertarr2ll(ARR);
    node = Insertion_of_tail_In_LL(node , 55);
    traversalLL(node);
}
