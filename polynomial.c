#include<stdio.h>
#include<stdlib.h>

struct node {
   int coeff;
   int power;
   struct node *next; 
};
struct node *start1,*start2,*start3,*newnode,*temp;

struct node * create(struct node *start){
  int n=1;
  while(n!=0){
  newnode=malloc(sizeof(struct node));
  printf("Enter the coefficent = ");
  scanf("%d",&newnode->coeff);
  printf("Enter the power =");
  scanf("%d",&n);
  newnode->power=n;
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
void display(struct node *start){
  printf("the display of the linked list is =");
  while(start!=NULL){
    printf(" coefficeint =%d power =%d \n",start->coeff,start->power);
    start=start->next;
  }

}

void createresult(int c,int p){
  newnode=malloc(sizeof(struct node));
  newnode->coeff=c;
  newnode->power=p;
  temp=start3;
  if(start3==NULL){
    start3=newnode;
    
  }else{
     while(temp->next!=NULL){
      temp=temp->next;
     }
     temp->next=newnode;
  }
}

void polynomialadd(){
  struct node* temp1;
  struct node *temp2;
  int c,p;
  temp1=start1;
  temp2=start2;
  while(temp1!=NULL || temp2 != NULL){
  if(temp1->power==temp2->power){
      c=temp1->coeff+temp2->coeff;
      p=temp1->power;
      temp1=temp1->next;
      temp2=temp2->next;
      createresult(c,p);
    }else {
        if(temp1->power>temp2->power){
          c=temp1->coeff;
          p=temp1->power;
          temp1=temp1->next;
          createresult(c,p);
        }else{
          c=temp2->coeff;
          p=temp2->power;
          temp2=temp2->next;
          createresult(c,p);
        }
    }
    
  }
  if(temp1==NULL){
      while(temp1!=NULL){
      c=temp1->coeff;
      p=temp1->power;
      temp1=temp1->next;
      createresult(c,p);
      }
  }else if(temp2==NULL){
    while(temp2!=NULL){
      c=temp2->coeff;
      p=temp2->power;
      temp2=temp2->next;
      createresult(c,p);
      }
  }


}


int main(){
start1=create(start1);
display(start1);
start2=create(start2);
display(start2);
polynomialadd();
display(start3);

}