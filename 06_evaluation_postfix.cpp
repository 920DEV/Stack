#include<bits/stdc++.h>

using namespace std;

// Precedance of "Operators" inside the stack;
int in_stack_pre(char exp){
    if(exp=='+'|| exp=='-'){
        return 2;
    }
   else if(exp=='*' || exp=='/')
        return 4;
    else if(exp=='^')
        return 5;
    else if(exp=='(')
        return 0; 
    
    else{
        return -1;
    }
}

// Precedance of "Operators" outside the stack:

int out_stack_pre(char exp){
       if(exp=='+'|| exp=='-'){
        return 1;
    }
   else if(exp=='*' || exp=='/')
        return 3;
    else if(exp=='^')
        return 6;

    else if(exp=='(')
        return 7; 
    else if(exp==')'){
        return 0;
    }
  else 
    return -1;
}

// Differentation between operator and operand.

int is_operand(char exp){
    if(exp=='+'|| exp=='-' || exp=='*'|| exp=='/' || exp=='^' || exp=='(' || exp==')'){
        return 0;
    }
    else{
        return 1;
    }
}

string evaluation(string infix){
    stack<char>st;
    st.push('#');


    int i=0,j=0;
    int n=infix.size();
    string postfix(n,'f');        // putting all the string as -1 as we can't leave string empty when the size is aleady declared.

    while(i<n){
        if(is_operand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else if(out_stack_pre(infix[i])==in_stack_pre(st.top())){
            st.pop();
        }
        else{
            if(out_stack_pre(infix[i])>in_stack_pre(st.top())){
                st.push(infix[i++]);
            }
            else{
                postfix[j++]=st.top();
                st.pop();
            }
        }

}
while(!st.empty() && st.top()!=')'){
    postfix[j++]=st.top();
    st.pop();
}
return postfix;
}

int main(){
   string infix="(a+b)*c-d^e^f";
   string posfix=evaluation(infix);
   posfix=posfix.substr(0,infix.size());
   cout<<posfix<<endl;
}