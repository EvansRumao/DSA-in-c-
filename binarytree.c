#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left,*right;
}*root;

void insert(){
  struct node *temp,*pre,*newnode;
  newnode =malloc(sizeof(struct node));
  temp=root;
  printf("Enter the data =");
  scanf("%d",&newnode->data);
  if(root==NULL){
    root=newnode;
  }
  else{
    while (temp!=NULL)
    {
      if(temp->data>newnode->data){
        pre=temp;
        temp=temp->left;
      }
      else{
        pre=temp;
        temp=temp->right;
      }
    }
    if(pre->data>newnode->data){
        pre->left=newnode;
    }else{
      pre->right=newnode;
    }
  }

}


void display_inorder(struct node *temp){
  if(temp!=NULL){
    display_inorder(temp->left);
    printf("%d ",temp->data);
    display_inorder(temp->right);
  }


}

int main(){
  int count;
  printf("Enter the number of nodes =");
  scanf("%d",&count);
  for(int i=0;i<count;i++){
    insert();
  }
  display_inorder(root);

}