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
void create(struct node *root,struct node *new);
void inorder(struct node *temp);

//main function goes here
void main(){
  char answer;
  struct node *root,*new;
  root=NULL;
do{


new=(struct node*)malloc(sizeof(struct node));
new->left=NULL;
new->right=NULL;

printf("Enter the data you want to store\n");
scanf("%d",&new->data);
if(root==NULL){

  root=new;
}
else{
  create(root,new);
}
printf("Do you want to continue?(y/n)\n");
answer=getch();
}while(answer=='y'||answer=='Y');

printf("***------INORDER-------***\n\n\n");
inorder(root);
 }


//create function goes here
void create(struct node *root,struct node *new){
char ans;
printf("Where to insert (L/R) of %d\n",root->data);
ans=getch();
if(ans=='l'||ans=='L'){
  if(root->left==NULL){
    root->left=new;
  }
  else{
    root=root->left;
    create(root,new);
  }

 }
else{
  if(ans=='R'||ans=='r'){
    if(root->right==NULL){
      root->right=new;
    }
    else{
      root=root->right;
      create(root,new);
        }
       }
  }
 }



 //inorder traversal goes like this
 void inorder(struct node *temp){
   if(temp!=NULL){
     inorder(temp->left);
     printf("%d ",temp->data);
     inorder(temp->right);
   }
 }
