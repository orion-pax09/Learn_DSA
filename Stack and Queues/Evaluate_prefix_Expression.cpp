#include <iostream>
using namespace std;
class Node{
    public:
    Node*ptr;
    int data;
    Node(int data){
        this->data =data;
        ptr = nullptr;
    }
};
class stack{
    public:
    Node*top;
    int arr[100];
    stack(){
    top = nullptr;
    } 
    void push(int x){
        Node*newNode = new Node(x);
        newNode->ptr = top;
        top = newNode;
    }
    int pop(){
        if (top==nullptr){
            return 0 ;
        }
        Node*temp = top;
        int data = temp->data;
        top = top->ptr;
        delete temp;
        return data;
    }
    int peek(){
        if (top == nullptr){
            return 0;
        }
        return top->data;
    }
    bool is_empty(){
        return top==nullptr;
    }
};
int priority(char op){
    if (op=='+'||op=='-'){
        return 1;
    }
    else if (op=='*'||op=='%'||op=='/'){
        return 2;
    }
    else if (op=='^'){
        return 3;
    }
    return 0;
}
int to_prefix(string prefix){
    int n = prefix.size();
    stack st;
    for (int i =n-1 ; i>=0 ; i--){
         if (prefix[i]>='0' && prefix[i]<='9'){
             st.push(prefix[i]-'0');
         }
         else{
            int a = st.pop();
            int b = st.pop();
            int res;
            if (prefix[i]=='+'){
                res =  a + b; 
            }
            else if (prefix[i]=='-'){
                res = a - b;
            }
            else if (prefix[i]=='*'){
                res = a * b;
            }
            else if (prefix[i]=='/'){
                res = a / b;
            }
            st.push(res);
        }
    }
    return st.pop();
}
int main(){
    cout << to_prefix("-/823"); // output :- 1
}
