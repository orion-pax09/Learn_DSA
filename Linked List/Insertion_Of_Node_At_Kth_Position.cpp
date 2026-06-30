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

Node*Insertion_Of_Node_At_Kth_Position(Node*head , int value , int k){
    if (head==nullptr){
        return new Node (value);
    }
    Node*temp = head;

    int count = 0;
    
    while (temp!=nullptr){
        count++;
        if (count == k - 1){
            Node*newNode = new Node(value);
            newNode->ptr = temp->ptr;
            temp->ptr = newNode;
        }
        temp = temp->ptr;
    }
    return head;
}


int main(){
    vector<int>ARR = {33,44,55,66,77};
    Node*node = convertarr2ll(ARR);
    node = Insertion_Of_Node_At_Kth_Position(node , 5, 4);
    traversalLL(node);
}
