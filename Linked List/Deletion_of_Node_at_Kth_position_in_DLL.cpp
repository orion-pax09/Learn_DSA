
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
    if (head==nullptr||head->ptr==nullptr){
        return nullptr;
    }
    Node*temp = head;
    while(temp->ptr!=nullptr){
        temp = temp->ptr;
    }
    Node*previous = temp->back;
    previous->ptr = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
Node*deletionofHead(Node*head){
    if (head==nullptr){
        return nullptr;
    }
    if(head->ptr == nullptr){
        delete head;
        return nullptr;
    }
    Node*newNode = head;
    Node*previous = head;
    newNode = head->ptr;
    newNode->back = nullptr;
    previous->ptr  = nullptr;
    delete previous;
    return newNode;
}
Node*deletionofnodeatKth(Node*head,int k){
    int count = 0;
    Node*temp = head;
    while (temp!=nullptr){
        count++;
        if (count == k){
            break;
        }
        temp = temp->ptr;
    }
    Node*front = temp->ptr;
    Node*previous = temp->back;
    if (head==nullptr){
        return nullptr;
    }
    if (front==nullptr&&previous==nullptr){
        delete temp;
        return nullptr;
    }
    else if (front==nullptr){
        return deletionoftail(head);
    }
    else if (previous==nullptr){
        return deletionofHead(head);
    }
    else{
        previous->ptr = front;
        front->back = previous;
        temp->back = nullptr;
        temp->ptr = nullptr;
        delete temp;
    }
    return head;
}
int main(){
    vector<int>arr = {44,55,22,33,11};
    Node*temp = convertArraytoDLL(arr);
    Node*node = deletionofnodeatKth(temp , 4);
    print(node);
}
