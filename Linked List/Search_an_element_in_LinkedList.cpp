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
    Node(int data1 , Node*pointer){
        data = data1;
        ptr = pointer;
    }
};
Node*convertArray2LL(vector<int>&arr){
    Node*head = new Node (arr[0]);
    Node*movers = head;
    for (int i = 1 ; i < arr.size() ; i++){
        Node*temp = new Node(arr[i]);
        movers->ptr = temp;
        movers = temp;
    }
    return head;
}
int searchLL(Node*node,int value){
    Node*temp  = node;
    while (temp!=nullptr){
        if (temp->data==value){
            return temp->data;
        }
        temp = temp->ptr;
    }
    return 0;
}
int main(){  
    vector <int> arr = {44,55,77,22,33};
    Node*temp = convertArray2LL(arr);
    cout << "Searched: "<<searchLL(temp , 55);
}
