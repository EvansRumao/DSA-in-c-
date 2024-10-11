#include<stdio.h>
#define size 50
int queue[size];
int front=-1,rear=-1;



void Enqueue(int x,int len){
  if(rear==len-1){
     printf("the queue is full");
  }else{ 
    if(rear==-1){
    front=0;
    rear=0;
    }else{
      rear++;
    }
   queue[rear]=x;

  }

}

void Dequeue(){
  int x;
  if(front==-1||front>rear){
    printf("stack is Empty\n");
  }
  else 
  {
    x=queue[front];
    printf("the deleted Element is =%d\n",x);
    front++;
    if(front>=rear){
      front =-1;
      rear=-1;
    }
  }
}


int main(){
  int len,num,num1;
  printf("Enter the number of elements =");
  scanf("%d",&len);

  printf("Enter the Elements=\n");
  for(int i=0;i<len;i++){
   scanf("%d",&num);
    Enqueue(num,len);
  }

 printf("Enqueue function is =\n");
   for(int i=front;i<=rear;i++){

    printf("%d\t",queue[i]);
    }

    printf("\n");


  printf("Enter the Enqueue Element =");
  scanf("%d",&num1);  
  Enqueue(num1,len);

  printf("Enqueue function is =\n");
   for(int i=front;i<=rear;i++){

    printf("%d\t",queue[i]);
    }



  // Dequeue();
  // Dequeue();
  // Dequeue();
  // Dequeue();


  return 0;

}