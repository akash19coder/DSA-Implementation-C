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
void inorder(struct node *temp);

//main function goes here
void main(){
  struct node *root;
  root=create();
  inorder(root);

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
   printf("Congrats! Your tree is created\n");
   return newnode;
 }



 //inorder traversal goes like this
 void inorder(struct node *root){
   if(root!=NULL){
     inorder(root->left);
     printf("%d ",root->data);
     inorder(root->right);
   }
 }
