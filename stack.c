#include<stdio.h>
#include <ctype.h>
#define size 30
char st[size],postfix[size];
char infix[size];
int  top=-1;

void push(char x){
  if(top==size){
    printf("stack is full");
  }else{
    top++;
    st[top]=x;
    
  }
}

int pop(){
  char x;
  if(top==-1){
    printf("stack is empty ");
    return '\0'; 

  }else{
    x=st[top];
    top--;
    return x;
  }
}

int precedence(char x){
  if(x=='+'|| x=='-'){
    return 1;
  }
  else if(x=='*'||x=='/'){
    return 2;
  }else{
    return 0;}
  

}

void infixtopostfix(){
  int j=0;
  int k=0;
  char str=infix[j];
  while(str!='\0'){

  if(isalnum(str)){
    postfix[k]=str;
    k++;
  }

  else if(str=='('){
    push(str);
  }

  else if(str==')'){
    while(st[top]!='('){
      postfix[k]=pop();
      k++;
    }
    pop();
  }

  else if(str=='+'||str=='*'||str=='-'||str=='/'){
    while (top != -1 && precedence(st[top]) >= precedence(str)) {
                postfix[k++] = pop();
            }
            push(str);

  }else{
    printf("Invalid syntax");
    }
    j++;
    str=infix[j];
    

  }
  
  while(top!=-1){
      postfix[k]=pop();
      k++;
      
    }

}

int main() {
     printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtopostfix();

    printf("Postfix expression: %s\n", postfix);

    return 0;
}