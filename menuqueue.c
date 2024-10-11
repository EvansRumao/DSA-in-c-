#include<stdio.h>
# define size 5
int qu[size];
int front=-1,rear=-1;

void enqueue(int x){
  if(rear==size-1){
    printf("queue is full");
  }else if(rear==-1){
     rear=0;
     front=0;
     qu[rear]=x;
  }else{
    rear++;
    qu[rear]=x;
  }
}

int Dequeue(){
  int x;
  if(front==-1){
    printf("the queue is Empty");
  }else if(front==rear){
    x=qu[front];
    front=-1;
    rear=-1;
    return x; 
  }else{
    x=qu[front];
    front++;
    return x;
  }
  return 0;
}

void display(){
  int y=front;
  while(y!=rear+1){
    printf("%d ",qu[y]);
    y++;
  }
}

int main(){
  int x;
  // printf("enter the Array elements =");
  // for(int i=0;i<5;i++){
  //   scanf("%d",&x);
  //   enqueue(x);
  // }
  enqueue(1);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  Dequeue();
  Dequeue();
  display();

  return 0;
}
