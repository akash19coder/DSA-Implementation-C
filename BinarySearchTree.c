/* Header files */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*Structure Node*/
struct node{
  int data;
  struct node *left;
  struct node *right;
};

//Global function declaration
void create(struct node *root, struct node *temp);
void search(struct node *root,int key);

/*Main function*/
void main(){
char answer;
struct node *temp,*root;
root=NULL;

do{
  temp = (struct node*) malloc(sizeof(struct node*));
  temp->left = NULL;
  temp->right = NULL;

  printf("Enter the data you want to store\n");
  scanf("%d",&temp->data);

  if(root==NULL){
    root=temp;
  }
  else{
    create(root,temp);
  }
  printf("Do you want to continue\n");
  answer=getch();
}while(answer=='y'||answer=='Y');

search(root,5);
}

void create(struct node *root, struct node *temp){
if(temp->data<root->data){
  if(root->left==NULL){
    root->left=temp;
  }
  else{
    create(root->left,temp);
  }
}
if(temp->data>root->data){
  if(root->right==NULL){
    root->right=temp;
  }
  else{
    create(root->right,temp);
  }
}

}


void search(struct node *root, int key){
  struct node *temp;
  temp=root;
   while(temp!=NULL){
       if(temp->data==key){
         printf("%d is available",temp->data);

       }
       else{
         if(key<temp->data && temp->data!=key){
            temp=temp->left;
            search(temp->left,key);
         }
         else{
             temp=temp->right;
             search(temp->right,key);
         }
       }
   }

}
