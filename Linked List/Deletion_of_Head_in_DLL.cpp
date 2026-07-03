
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
Node*deletionofhead(Node*head){
    if (head == nullptr){
        return nullptr;
    }
    if (head->ptr == nullptr){
        delete head;
        return nullptr;
    }

    Node*HEAD = head;
    Node*previous=HEAD;
    HEAD = head->ptr;
    HEAD->back = nullptr;
    previous->ptr=nullptr;
    delete previous;
    return HEAD;
}
int main(){
    vector<int>arr = {44,55,22,33,11};
    Node*temp = convertArraytoDLL(arr);
    Node*node= deletionofhead(temp);
    print(node);
}
