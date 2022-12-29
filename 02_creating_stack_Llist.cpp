#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    


};

void push(Node* &st,int data){
    // ~creating a new node.
    Node* t=new Node;
    if(t==NULL){
        cout<<"stack is overflowed"<<endl;

    }
    else{
        t->data=data;
        t->next=st;
        st=t;
    }
}

// removing the last inserted element in the stact(LIFO)
int pop(Node* &st){
    int x=-1;
    Node*t=new Node;
    if(st==NULL){
        cout<<"The stack is emptly(underflowed)"<<endl;
    }
    else{
            t=st;
            st=st->next;
            x=t->data;

            delete t;
            
    }
    return x;
}


void display(Node* st){
    Node*temp=st;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
    cout<<" "<<endl;
}
int main(){


Node*header=new Node;
header=NULL;
push(header,1);
push(header,2);
push(header,3);
push(header,4);

display(header);
cout<<"Removing some elements of the stack using linked list using the function pop"<<endl;
cout<<"The deleted element is : "<< pop(header)<<endl;
display(header);


return 0;
}
