/* Converting Infix to postfix 
Infix -: a+b*c/-e+d, this is a infix statement 
postfix-: abc+d */
#include<bits/stdc++.h>


using namespace std;

class Node{
    public:
    char data;
    Node*next;

};

class Stack {
    private:
        Node* top;

    public:
        Stack()
        {
            this-> top = NULL;
        }
    // ~ destructor for delting element in the stack

        // ~stack(){
        //     Node*temp=top;
        //     string x=temp->data;
        //     if(top!=NULL){
        //         top=top->next;
        //         delete temp;
        //         temp=top;
        //     }
        //     cout<<"The delted element is "<<x<<endl;
        // }

        void push(char data){     // pushing element in stack.
            Node*t = new Node;
            if(t==NULL){
                cout<<"Stack overflow"<<endl;
            }
            t->data=data;
            t->next = top;
            top=t;
            

        }
    char pop(){
        char x= -1;
        Node* temp= top;
        if(top== NULL){
            cout<<"Stack is Underflow"<<endl;
        }
        else{
            x= temp->data;
            top=top->next;
            delete temp;
            
        }
        return x;

    }

    // function for checking wheather the stadk is empty or not
    int isEmpty() {
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
}


void display(){
    Node*temp=top;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    cout<<" "<<endl;
}
// functions for converting infix to postfix.
int is_operand(char exp)
{
    if(exp=='+'|| exp=='-' || exp=='*'|| exp=='/'){
        return 0;
    }
    else{
        return 1;
    }
}
// checking the prendance of the operators.

int pre(char exp){
    if(exp =='+'|| exp =='-' ){
        return 1;
    }
    else if(exp=='*'|| exp=='/'){
        return 2;
    }
    else{
        return 0;
    }
}
// converting the expression
 char *convert(char* infix){
    int a =strlen(infix);
    char *postfix= new char(a+2);
    cout<<a<<endl;
    int i=0,j=0;
    while (infix[i]!='\0')
    {
        if(is_operand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(pre(infix[i]>pre(top->data))){
                push(infix[i++]);
            }
            else{
                postfix[j++]=pop();
            }
        }
    
        
    }
       while(top != NULL){
        postfix[j++]=pop();
    }
    postfix[j] = '\0';
    return postfix;
 }

};

int main(){
    Stack st;

char infix []="a+b*c-d/e";
 st.push('#');
  st.display();
 char *postfix=st.convert(infix);
 cout<<postfix<<endl;
    return 0;
}