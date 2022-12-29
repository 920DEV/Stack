#include<iostream>
using namespace std;

class Node{
    public:
    int size;
    int top;
    int *s;

    Node(){
      cout<<"Enter the size of the stack: "<<endl;
    cin>>this->size;
    this->top=-1;
    // Dynamically allocating stack.
    this->s=new int(this->size);
}

};


// ! Making constrctor for creating stack in headp;

// ~ function for creatng stack;
// void create_stack(Node*st){
//     cout<<"Enter the size of the stack: "<<endl;
//     cin>>st->size;
//     st->top=-1;
    // Dynamically allocating stack.
//     st->s=new int(st->size);
// }
void push(Node*st,int data){
    if(st->top>=st->size-1){
        cout<<"stack overflowed: "<<endl;
    }
    else{
        st->top++;
        st->s[st->top]=data;
        cout<<st->top<<endl;

    }
}
// for deleting the top most element in stack;
int pop(Node *st){
    int x=-1;
    if(st->top==-1){
        cout<<"Stack is Underflowed"<<endl;
    }
    else{
        x=st->s[st->top];
        st->top--;
        
    }
    return x;
}
// checking wheater the stack is empty or not
void empty(Node* st){
    if(st->top==-1){
        cout<<"The stack Underflowed"<<endl;
    }

}

// whateher the stack is full or not.(overflowed);
void full(Node *st){
    if(st->top>st->size-1){
        cout<<"stack is overflowed"<<endl;
    }
}
// ~ Function for peeking in stack
int peek(Node st,int position){
    if(position>st.size-1){
        return -1;
    }
    else{
        return st.s[position];
    }
}

// checking the top most element:
int check_top(Node st){
    
}
// displaying stack

void display_stack(Node st){
   for (int i = st.top; i >= 0; i--)
   {
    cout<<st.s[i]<<endl;
   }
}

int main(){
    Node st;
    // create_stack(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    push(&st,60);
    
   
    display_stack(st);
    int position;
    cout<<"Enter the the position of element you wants to peek: "<<endl;
    cin>>position;
    cout<<peek(st,position)<<endl;


    cout<<"The deleted element is :"<<pop(&st)<<endl;
    display_stack(st);

    return 0;
}