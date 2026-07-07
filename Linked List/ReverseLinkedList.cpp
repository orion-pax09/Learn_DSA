#include <iostream>
using namespace std;
#include <vector>
class Node{
    public:
    int data;
    Node*ptr;
    Node(int data1){
        data=data1;
        ptr = nullptr;
    } 
    Node(int data1 , Node*ptr1){
        data = data1;
        ptr = ptr1;
    }
};
Node*convertarraytoLL(vector<int>&arr){
    Node*head =new Node (arr[0]);
    Node*movers = head;
    for (int i = 1 ; i < arr.size() ; i++){
        Node*temp = new Node(arr[i]);
        movers->ptr = temp;
        movers=temp;
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
Node*reverseLL(Node*head){
    if (head==nullptr||head->ptr == nullptr){
        return head;
    }
    Node*previous = nullptr;
    Node*next = nullptr;
    Node*current = head;
    while (current!=nullptr){
        next = current->ptr;
        current->ptr = previous;
        previous = current;
        current = next;
    }
    return previous;
}
int main(){
    vector <int>arr = {1,2,3,4,5};
    vector <int>arr1 = {6,7,8,6,4,3,2,6,7,8,9,0};
    Node*temp= convertarraytoLL(arr);
    Node*temp1 = convertarraytoLL(arr1);
    Node*reverse1 = reverseLL(temp1);
    Node*reverse2 = reverseLL(temp);
    print(reverse2);    
}
