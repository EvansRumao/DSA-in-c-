#include<stdio.h>
#include<stdlib.h>

struct node{
  int coeff;
  int power;
  struct node *next;
};

struct node *start1,*start2,*start3,*temp,*newnode;

struct node * create(struct node *start){
  int n=0;
  while(n!=-1){
  newnode=malloc(sizeof(struct node ));
  printf("enter the coefficient =");
  scanf("%d",&newnode->coeff);
  printf("Enter the power =");
  scanf("%d",&newnode->power);
  printf("to continue adding press 1 to finish press -1=");
  scanf("%d",&n);
  if(start==NULL){
     start=newnode;
  }else{
    temp=start;
    while(temp->next!=NULL){
      temp=temp->next;
      
    }
    temp->next=newnode;
  }


  }

  return start;

}

void createresult(int c,int p){
  newnode=malloc(sizeof(struct node));
  newnode->coeff=c;
  newnode->power=p;
  temp=start3;
  if(temp==NULL){
    start3=newnode;
  }else{
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newnode;
  } 

}

void polysum(){
  struct node *temp1;
  struct node *temp2;
  int c,p;
  temp1=start1;
  temp2=start2;
  while(temp1!=NULL && temp2!=NULL){
    if(temp1->power==temp2->power){
      c=temp1->coeff+temp2->coeff;
      p=temp1->power;
      temp1=temp1->next;
      temp2=temp2->next;
      createresult(c,p);
    }
    else if(temp1->power > temp2->power){
      c=temp1->coeff;
      p=temp1->power;
      temp1=temp1->next;
      createresult(c,p);
    }
    else{
      c=temp2->coeff;
      p=temp2->power;
      temp2=temp2->next;
      createresult(c,p);
    }
  }

  if(temp2==NULL){
      while(temp1!=NULL){
      c=temp1->coeff;
      p=temp1->power;
      temp1=temp1->next;
      createresult(c,p);
      }
  }else if(temp1==NULL){
    while(temp2!=NULL){
      c=temp2->coeff;
      p=temp2->power;
      temp2=temp2->next;
      createresult(c,p);
      }
  }

}



void display(struct node *start){
  printf("\n");
   while(start!=NULL){
    printf("%dx^%d ",start->coeff,start->power);
    start=start->next;

   }
   printf("\n");
}

int main(){

  start1=create(start1);
  display(start1);
  start2=create(start2);
  display(start2);

  polysum();
  display(start3);

}
