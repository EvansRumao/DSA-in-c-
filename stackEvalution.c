#include<stdio.h>
#include <ctype.h>
#define size 30
char st[size],postfix[size];
char infix[size];
int stack[size];
int  top=-1;
int top1=-1;

//to convert infix to postfix
void push(char x){
  if(top==size-1){
    printf("stack is full");
  }else{
    top++;
    st[top]=x;
    
  }
}

//to Evaluate postfix expression 
void push1(int x){
  if(top1==size-1){
    printf("stack is full");
  }else{
    top1++;
    stack[top1]=x;
    
  }
}

//pop for infix to postfix
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


//evaluate pop
int pop1(){
  int x;
  if(top1==-1){
    printf("stack is empty ");
    return 0; 

  }else{
    x=stack[top1];
    top1--;
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


int Evalution(){
  int i=0;
  char c;
  int op1,op2,result;
  while (postfix[i]!='\0')
  {
    c=postfix[i];
    
    if(isdigit(c)){
     int y=c-'0';
      push1(y);
    }
    else if(c=='+'||c=='-'||c=='*'||c=='/'){
        op2=pop1();
        op1=pop1();
        if(c=='+'){
         result=op1+op2;
        }
        else if(c=='-'){
         result=op1-op2;
        }
        else if(c=='*'){
         result=op1*op2;
        }
        else if(c=='/'){
         result=op1/op2;
        }
        else{
       printf("invalid operator ");
      return 0;
    }

        push1(result);
    }
    
    i++;
  }
  
  return pop1();


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

    postfix[k]='\0';

}

int main() {
     printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtopostfix();

   printf("Postfix expression: %s\n", postfix);
    int result=Evalution();

     printf("the answer is =%d",result);

    return 0;
}