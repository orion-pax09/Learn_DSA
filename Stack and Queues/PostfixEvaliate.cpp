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
int postEvaluate(string postfix){
    int n = postfix.size();
    stack st;
    for (int i = 0 ; i < n ; i++){
         if (postfix[i]>='0' && postfix[i]<='9'){
             st.push(postfix[i]-'0');
         }
         else{
            int a = st.pop();
            int b = st.pop();
            int res;
            if (postfix[i]=='+'){
                res =  a + b; 
            }
            else if (postfix[i]=='-'){
                res = b-a;
            }
            else if (postfix[i]=='*'){
                res = a * b;
            }
            else if (postfix[i]=='/'){
                res = b/ a;
            }
            st.push(res);
        }
    }
    return st.pop();
}
int main(){
    cout << postEvaluate("532*+84/-"); // output : 9
}
