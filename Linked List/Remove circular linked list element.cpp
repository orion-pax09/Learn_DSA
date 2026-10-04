// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    Node*ptr;
    int data;
Node(int val){
    data = val;
    ptr = nullptr;
}
Node(int data , Node*ptr1){
    this->data = data;
    ptr = ptr1;
}
};
Node*convertvectortoLL(vector<int>arr){
    Node*head = new Node(arr[0]);
    Node*movers = head;
    for (int i = 1 ; i < arr.size() ; i++){
        Node*temp = new Node(arr[i]);
        movers->ptr = temp;
        movers = temp;
    }
    return head;
}
void traverse(Node*head){
    Node*temp = head;
    do{
        cout << temp->data<<" ";
        temp = temp->ptr;
        
    }
        while(temp!=head);
}
Node*CLL(Node*head){
    if (head == nullptr){
        return head;
    }
    Node*temp = head;
    while(temp->ptr!=nullptr){
        temp = temp->ptr;
    }
    temp->ptr = head;
    return head;
}
void deleteAllCLL(Node*&head , int target){
    if(head!=nullptr){
        Node*last = head;
        while(last->ptr!=head){
            last = last->ptr;
        }
        Node*current = head;
        Node*prev = last;
        bool finished = false;
        while(!finished&&head!=nullptr){
            if(current->data == target){
                if (current == current->ptr){
                    delete current;
                    head = nullptr;
                    finished = true;
                }
                else{
                    Node*deletenode = current;
                    prev->ptr = current->ptr;
                    if (current == head){
                        head = head->ptr;
                    }
                    current = current->ptr;
                    delete deletenode;
                    if (current == head){
                        finished = true;
                    }
                }
            }
            else{
                prev = current;
                current = current->ptr;
                if (current==head){
                    finished = true;
                }
            }
        }
    }
}
int main(){
    vector<int>array = {22,33,44,22,66,77};
    Node*to_Array = convertvectortoLL(array);
    Node*cll = CLL(to_Array);
    cout << "before delete"<<endl;
    traverse(cll);
    cout << "\nAfter delete"<<endl;
    deleteAllCLL(cll , 22);
    traverse(cll);
}
