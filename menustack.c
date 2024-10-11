#include<stdio.h>
# define size 5
int top=-1;
int stack[size];

void push(int x)
{
 if(top==size-1){
  printf("stack is full");
 }else{
  top++;
  stack[top]=x;
 }
}

void pop(){
  int y;
  if(top==-1){
    printf("stack is empty =");
  }else{
    y=stack[top];
    top--;
    printf("the deleted element is = %d\n",y);
  }
  
}

void display(){
  int k=top;
  if(k==-1){
    printf("stack is empty\n");
  }else{
  while (k!=-1)
  {
    printf("%d ",stack[k]);
    k--;
  }
  printf("\n");
  }
}
void peek(){
  if(top==-1){
    printf("stack is empty");
  }else{
    printf("stack top is = %d\n",stack[top]);
  }
}
int main(){
   int x;
   //printf("enter the elements=");
  // for(int i=0;i<5;i++){
  //   scanf("%d",&x);
  //   push(x);
  // }
  // pop();
  // peek();
  // printf("the stack is =");
  // display();
  int sel;
  int n=1;
  while(n){
    printf("for push press 1 \n for pop press 2 \n  for peek press 3 \n for display of all elements press 4 \n for exit press 5  ==");
    scanf("%d",&sel);
    switch (sel)
    {
    case 1: printf("enter the element=");
       scanf("%d",&x);
       push(x);
      break;

    case 2:pop();
        break;  
    
    case 3:peek();
       break;
    case 4:display();
      break;

    case 5:n=0;
      break;
    default:printf("wrong entry try again ");
      break;
    }


  }

  return 0;
}