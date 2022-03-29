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
  root=create();
  inorder(root);
  preorder(root);
  postorder(root);

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
     printf("%d",root->data);
     inorder(root->right);
   }
 }

//preorder traversal function goes like this
 void preorder(struct node *root){
   if(root!=NULL){
     printf("%d",root->data);
     preorder(root->left);
     preorder(root->right);
   }
 }

//postorder traversal function goes like this
 void postorder(struct node *root){
   if(root!=NULL){
     postorder(root->left);
     postorder(root->right);
     printf("%d",root->data);
   }
 }
