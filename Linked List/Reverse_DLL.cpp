#include <iostream>
using namespace std;
#include <vector>
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
    Node(int data1,Node*ptr1 , Node*back1){
        data = data1;
        ptr = ptr1;
        back = back1;
    }
};
Node*convrtarrtoDLL(vector<int>&arr){
    Node*head = new Node(arr[0]);
    Node*previous = head;
    for (int i = 1 ; i < arr.size() ; i++){
        Node*temp = new Node(arr[i] , nullptr , previous);
        previous->ptr = temp;
        previous = temp;
    }
    return head;
}
Node*reverseDLL(Node*head){
    if (head == nullptr||head->ptr==nullptr){
        return head;
    }
    Node*current = head;
    Node*last = nullptr;
    while(current!=nullptr){
        last = current->back;
        current->back = current->ptr;
        current->ptr = last;
        current = current->back;
    }
    return last->back;
}
void print(Node*head){
    Node*temp = head;
    while(head!=nullptr){
        cout << head->data << " ";
        head = head->ptr;
    }
}
int main(){
    vector<int>array = {22,11,33,44,55};
    Node*temp = convrtarrtoDLL(array);
    Node*reverse = reverseDLL(temp);
    print(reverse);
}
