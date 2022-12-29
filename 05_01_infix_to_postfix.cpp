#include<bits/stdc++.h>

using namespace std;


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





string convert(string infix){
    stack<char>st;
     st.push('#');

    int i=0,j=0;
    int n=infix.size();
    string postfix(n+1,'f');

    while (i<n)
    {
        if(is_operand(infix[i])){
            postfix[j++]=infix[i++];

        }

        
        else{
            if(pre(infix[i])>pre(st.top())){
                st.push(infix[i++]);
            }
            else{
                postfix[j++]=st.top();
                st.pop();
            }
        }
    }
    while (!st.empty())
    {
        postfix[j++]=st.top();
        st.pop();
    }
        return postfix;
}

int main(){
    string infix="a+b*c-d/e";
   

string postfix= convert(infix);

postfix=postfix.substr(0,infix.size());
cout<<postfix<<endl;
    return 0;

}