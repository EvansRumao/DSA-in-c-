#include<stdio.h>
# define size 40
int rear=-1,front=-1;
int q[size];

void Enqueue(int x,int len){
  if(front==(rear+1)%len){
    printf("queue is full");
  }else if(rear==-1){
    front=0;
    rear=0;
    q[rear]=x;
  }
  else{
    rear=(rear+1)%len;
    q[rear]=x;
  }
}


int Dequeue(int len){
  int x;
  if(front==-1){
     printf("queue is empty");
     
  }else if(front==rear){
     x=q[front];
    front =-1;
    rear=-1;
    printf(" the deleted =%d",x);
  }else{
    x=q[front];
    front=(front+1)%len;
    printf("the deleted =%d",x);
  }
   
   return 2;

  
}

void Display(int len) {
    if (front==-1&&rear==-1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Elements in the circular queue are: ");
    int i = front;
    do {
        printf("%d ", q[i]);
        i = (i + 1) % len;
    } while (i != (rear + 1) %len);
    printf("\n");
}

int  Input(){
  int len,y;
  printf("Enter the length of the Queue=");
  scanf("%d",&len);
  printf("Enter the queue Elements =");
  for(int i=0;i<len;i++){
    scanf("%d",&y);
    Enqueue(y,len);
  }
  return len;

}

int main(){
  int n=0,len;
  while(n!=4){
    if(n==0){
    printf("welcome to the queue program\nEnter 1 for Enqueu\tEnter 2 for Dequeu \t Enter 3 for Display \t Enter 4 for Exit :");
    scanf("%d",&n);

   switch (n)
   {
   case 1: len=Input();
          n=1;
    break;

   case 2:n=Dequeue(len);
          
    break;

    case 3:Display(len);
    break;
   }
  }else if(n==1||n==2||n==3){
    printf("\nEnter 1 for Enqueu\tEnter 2 for Dequeu \t Enter 3 for Display \t Enter 4 for Exit :");
    scanf("%d",&n);

   switch (n)
   {
   case 1: len=Input();
          n=1;
    break;

   case 2:Dequeue(len);
          n=2;
    break;

    case 3:Display(len);
    break;

  }}
  else{
    printf("Invalid Input");
    n=4;
  }
  
  
  
  }
  
  return 0;
}