#include <iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node*ptr;
    Node(int data1){
        data=data1;
        ptr = nullptr;
    }
    Node(int data1 , Node*ptr1){
        data=data1;
        ptr = ptr1;
    }
};
Node*convertarray2LL(vector<int>arr){
    Node*head = new Node (arr[0]);
    Node*mover = head;
    for (int i = 1 ; i < arr.size(); i++){
        Node*temp = new Node (arr[i]);
        mover->ptr = temp;
        mover = temp;
    }
    return head;
}
int main(){
    vector <int>arr = {3,5,6,7,8,90};
    Node*node = convertarray2LL(arr);
    Node*temp = node;
    while (node!=nullptr){
        cout << temp->data<<" ";
        temp = temp->ptr;
    }
}