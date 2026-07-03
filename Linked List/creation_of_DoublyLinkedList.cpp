#include <iostream>
#include <vector>
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
        back = back1;
        ptr = ptr1;

    }
};
Node*covertArrintoDLL(vector<int>&arr){
Node*head = new Node(arr[0]);
Node*previous=head;
for (int i = 1 ; i < arr.size() ; i++){
    Node*temp = new Node(arr[i] , nullptr , previous);
    previous->ptr = temp;
    previous = temp;
}
return head;
}
void print(Node*head){
    Node*temp = head;
    while(temp!=nullptr){
        cout << temp->data<<" ";
        temp = temp->ptr;
    }
}
int main(){
    vector<int>array = {33,44,55,66,77,88};
    Node*temp = covertArrintoDLL(array);
    print(temp);
}
