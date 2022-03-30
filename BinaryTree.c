#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Structure  Declaration goes here
struct node{
  int data;
  struct node *left;
  struct node *right;
};


//Global  declaration section goes Where
struct node* create();
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);

//main function goes here
void main(){
struct node *root;
int choice;
char ans;
do{
printf("Enter your choice\n");
printf("1.Creating tree\n");
printf("2.Inorder Traversal\n");
printf("3.Preorder Traversal\n");
printf("4.Postorder Traversal\n");
scanf("%d",&choice);
switch(choice){
  case 1:
  root = create();
  break;

  case 2:
  printf("*----Inorder Traversal----*\n");
  inorder(root);
  break;

  case 3:
  printf("*----Preorder Traversal----*\n");
  preorder(root);
  break;

  case 4:
  printf("*----Postorder Traversal----*\n");
  postorder(root);
  break;

  default:
  printf("Please Enter the correct value\n");
}
printf("\nDo you want to continue(Y/N)\n");
ans=getch();
}while(ans=='y'||ans=='Y');


 }


//create function goes here
struct node* create(){
   int x;
   struct node *newnode;
   newnode = (struct node*) malloc(sizeof(struct node));
   printf("Enter the data(-1 if no data)\n");
   scanf("%d",&x);
   if(x==-1){
     return 0;
   }
   newnode->data = x;
   printf("You are entering left node of %d\n",x);
   newnode->left=create();
   printf("You are entering right node of %d\n",x);
   newnode->right=create();

   return newnode;
 }



 //inorder traversal function goes like this
 void inorder(struct node *root){
   if(root!=NULL){
     inorder(root->left);
     printf("%d ",root->data);
     inorder(root->right);
   }
 }

// preorder traversal function goes like this
 void preorder(struct node *root){

   if(root!=NULL){
     printf("%d ",root->data);
     preorder(root->left);
     preorder(root->right);
   }
 }

//postorder traversal function goes like this
 void postorder(struct node *root){

   if(root!=NULL){
     postorder(root->left);
     postorder(root->right);
     printf("%d ",root->data);
   }
 }
