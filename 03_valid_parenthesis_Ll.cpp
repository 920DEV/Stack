#include <bits/stdc++.h>
using namespace std;
 
class Node{
public:
    char data;
    Node* next;
};
 



class Stack{
private:
    Node* top;
public:
 Stack() {
   this-> top = NULL;
}
 
~Stack() {
  Node*temp =top;
  while (top!=NULL)
  {
    top=top->next;
    delete temp;
    temp=top;
  }
  
}
 
void push(char x) {
    Node* t = new Node;
    if (t == NULL){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}
 // removing top element fromt the stack
int pop() {
    Node* p;
    int x = -1;
    if (top == NULL){
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}
// !checking wheather the stack is full or not
int isFull() {
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}
 // checking wheather the stack is empty or not
int isEmpty() {
    return top ? 0 : 1;
}
// shows the top element of the stack 
int stackTop() {
    if (top!=NULL){
        return top->data;
    }
    return -1;
}
 // ~ function for checking the element at the given index
int peek(int index) {
    if (isEmpty()){
        return -1;
    } else {
        Node* p = top;
 
        for (int i=0; p != NULL && i<index-1; i++){
            p = p->next;
        }
 
        if (p != NULL){
            return p->data;
        } else {
            return -1;
        }
    }
}

// checking valid parenthis
bool valid_parenthis(string exp){
    for (int i = 0; exp[i]!= '\0'; i++)
    {
        if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            if(top==NULL){
                return false;
            }
            else{
                pop();
            }
        }

    }
    if(top==NULL){
        return true;

    }
    else{
        return false;
    }
    

}

};

 

 
int main() {
Stack st;
string exp = "(a+b)+(c)" ;

cout<<st.valid_parenthis(exp)<<endl;
    return 0;
} 