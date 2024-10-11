#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*front,*rear;

struct node *newnode;

void enqueue(){
  newnode=malloc(sizeof(struct node));
  printf("Enter the value =");
  scanf("%d",&newnode->data);
  if(rear==NULL){
    front=newnode;
    rear=newnode;
  }else{
    rear->next=newnode;
    rear=newnode;
  }

}

void dequeue(){
  struct node *temp;
  if(front==NULL){
    printf("Queue is Empty ");
  }else if(front==rear){
    printf("the deleted Element is =%d\n",front->data);
    //  temp=front
    // free(temp);
    front=NULL;
    rear=NULL;
  }else{
    printf("the deleted data is =%d\n",front->data);
    temp=front;
    front=front->next;
    free(temp);
  }
}

void display(){
  struct node * dis;
  dis=front;
  while(dis->next!=NULL){
     printf("%d",dis->data);
     dis=dis->next;
  }
  printf("%d",dis->data);
}


int main(){
  for(int i=0;i<3;i++){
  enqueue();
  }
  dequeue();
  display();

 return 0;
}