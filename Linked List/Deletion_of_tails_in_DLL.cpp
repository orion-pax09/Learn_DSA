
#include <vector>
#include <iostream>
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
        data = data1;
        ptr = ptr1;
        back = back1;
    }
};
Node*convertArraytoDLL(vector<int>&arr){
    Node*head = new Node(arr[0]);
    Node*previous = head;
    for (int i = 1 ; i < arr.size() ; i++){
        Node*Temp = new Node(arr[i] , nullptr , previous);
        previous->ptr = Temp;
        previous = Temp;
    }
    return head;
}
void print(Node*head){
    while(head!=nullptr){
        cout << head->data<<" ";
        head = head->ptr;
    }
}
Node*deletionoftail(Node*head){
    if (head==nullptr){
        return nullptr;
    }
    if (head->ptr == nullptr){
        return nullptr;
    }

    Node*tail = head;
    while (tail->ptr!=nullptr){
        tail = tail->ptr;
    }
    Node*previous = tail->back;
    previous->ptr = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}
int main(){
    vector<int>arr = {44,55,22,33,11};
    Node*temp = convertArraytoDLL(arr);
    Node*node = deletionoftail(temp);
    print(node);
}
