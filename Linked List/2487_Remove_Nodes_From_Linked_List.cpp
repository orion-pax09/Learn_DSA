#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node*ptr;
    Node(int data1){
        data = data1;
        ptr = nullptr;
    }
    Node(int data1 , Node*ptr1){
        data = data1;
        ptr = ptr1;
    }
};
Node*traversaltoarray(vector<int>&arr){
    Node*head = new Node (arr[0]);
    Node*movers = head;
    for (int i = 1 ; i < arr.size() ; i++){
        Node*temp = new Node (arr[i]);
        movers->ptr = temp;
        movers = temp;
    }
    return head;
}
void print(Node*head){
    while(head!=nullptr){
        cout << head->data<<" ";
        head = head->ptr;
    }
}
Node*reverseLL(Node*head){
    if (head == nullptr||head->ptr==nullptr){
        return head;
    }
    Node*current = head;
    Node*previous = nullptr;
    Node*next = nullptr;
    while (current!=nullptr){
        next = current->ptr;
        current->ptr = previous;
        previous = current;
        current = next;
    }
    return previous;
}
Node*RemoveNodetoright(Node*head){
    head = reverseLL(head);
    Node*current = head;
    Node*temp;
    Node*maxNode = head;
    while (current!=nullptr&&current->ptr!=nullptr){
        if (maxNode->data > current->ptr->data){
            temp = current->ptr;
            current->ptr = temp->ptr;
            delete temp;
        }
        else{
            current = current->ptr;
            maxNode = current;
        }
    }
    return reverseLL(head);
}
int main(){
    vector<int>array = {5,2,13,3,8};
    Node*temp = traversaltoarray(array);
    Node*remove = RemoveNodetoright(temp);
    print(remove);
}
