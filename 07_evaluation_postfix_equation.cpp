#include<iostream>
#include<stack>

using namespace std;


bool is_operand(char exp){
       if(exp=='+'|| exp=='-' || exp=='*'|| exp=='/' || exp=='^' || exp=='(' || exp==')'){
        return 0;
    }
    else{
        return 1;
    }
}
int convert_infix(string postfix)
{
    stack<int>st;
    int exp1,exp2,result;
    for (int i = 0; postfix[i]!='\0'; i++)
    {
        if(is_operand(postfix[i])){
            st.push(postfix[i]-'0');
            cout<<"the value "<<postfix[i]<<endl;
        }
        else{
            exp2=st.top();
            st.pop();
            exp1=st.top();
            st.pop();
              cout<<"the value "<<postfix[i]<<endl;
            switch (postfix[i])
            {
            case '+':
                result=exp1+exp2;
                cout<<result<<endl;
                st.push(result);
                break;
            case '-':
                result=exp1-exp2;
                 cout<<result<<endl;
                st.push(result);
                break;
            case '*':
                result=exp1*exp2;
                 cout<<result<<endl;
                st.push(result);
                break;
            case '/':
                result=exp1/exp2;
                 cout<<result<<endl;
                st.push(result);
                break;
            
            default:
                break;
            }
        }
    }
    return st.top();

    
}

int main(){
    string postfix="35*62/+4-";

   int a= convert_infix(postfix);
   cout<<a<<endl;

    return 0;
}