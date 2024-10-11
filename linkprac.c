#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
}*start=NULL;

struct node *newnode,*temp;


void insert(){
  int x;
  newnode=malloc(sizeof(struct node));
  printf("enter the number of elements =");
  scanf("%d",&x);
  while(x+1!=0){
  printf("Enter the element =");
  scanf("%d",&newnode->data);
  
  if(start==NULL){
    start=newnode;
    
  }else{
    temp=start;
    while (temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=newnode;
    
  }
  x--;
  }

}

void insert_before(){
  int x;
  struct node *p;
  newnode=malloc(sizeof(struct node));
  printf("Enter the element beofe which u want to enter =");
  scanf("%d",&x);
  printf("enter the new element =");
  scanf("%d",&newnode->data);
  temp=start;
  while(temp->data!=x){
    p=temp;
    temp=temp->next;
  }
  if(temp==start){
    start=newnode;
    newnode->next=temp;
  }else{
    newnode->next=temp;
    p->next=newnode;
  }
  
}

void insert_after(){
  int x;
  newnode=malloc(sizeof(struct node));
  printf("Enter the element after which u want to enter =");
  scanf("%d",&x);
  printf("Enter the element u want to add =");
  scanf("%d",&newnode->data);
  while(temp->data!=x){
    temp=temp->next;
  }
  newnode->next=temp->next;
  temp->next=newnode;
}

void delete(){
  struct node *p;
  int x;
  printf("enter the value u want to delete=");
  scanf("%d",&x);
  temp=start;
  while (temp->data!=x)
  {
    p=temp;
    temp=temp->next;
  }
  if(temp==start){
    start=temp->next;
    free(temp);
  }else if(temp==NULL){
     printf("not found");
  }else{
    p->next=temp->next;
  }
  
}


void delete_input_postion(){
  struct node *p;
  int x;
  printf("enter the positon =");
  scanf("%d",&x);

  temp=start;
  while (x!=0)
  {
    p=temp;
    temp=temp->next;
    x--;
  }
  if(temp==start){
    start=temp->next;
    free(temp);
  }else if(temp==NULL){
     printf("not found");
  }else{
    p->next=temp->next;
  }
  
}


void Display(){
  temp=start;
  while(temp->next!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("%d",temp->data);
}

int main(){
insert();
// insert_after();
// insert_before();
delete();
Display();
}

