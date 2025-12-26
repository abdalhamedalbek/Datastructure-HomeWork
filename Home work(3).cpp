#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x){ stack[++top] = x; }
char pop(){ return stack[top--]; }

int priority(char x){
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    return 0;
}

int main(){
    char exp[] = "3+4*(2-1)";
    char out[100];
    int k=0;

    for(int i=0; exp[i]; i++){
        if(isdigit(exp[i]))
            out[k++] = exp[i];
        else if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')'){
            while(stack[top] != '(')
                out[k++] = pop();
            pop();
        } else {
            while(top!=-1 && priority(stack[top]) >= priority(exp[i]))
                out[k++] = pop();
            push(exp[i]);
        }
    }

    while(top!=-1)
        out[k++] = pop();

    out[k]='\0';
    printf("Postfix: %s\n", out);
}
