#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Global declaration of user-defined function
struct node* create(struct node *root,struct node *New);
void preorder(struct node* root);
void inorder(struct node* root);
void postorder(struct node* root);

// Structure declaration
struct node{
  int data;
  struct node *left;
  struct node *right;
};


void main(){
  char ans;
  struct node *root;
  struct node *New;
  root=NULL;
  do{


    New=(struct node*)malloc(sizeof(struct node));
    New->left=NULL;
    New->right=NULL;
    printf("Enter the data\n");
    scanf("%d",&New->data);
    if(root==NULL){
      root=New;
    }
    else{
      create(root,New);
    }
printf("Do you want to enter more data(y/n)\n");
ans=getch();
  }while(ans=='y'||ans=='Y');


}

struct node* create(struct node *root,struct node *New){
char ch;
printf("Where to insert (right or left) of %d\n\n",root->data);
ch=getch();
if(ch=='R'||ch=='r'){
  if(root->right==NULL){
    root->right=New;
    }
    else{
      create(root->right,New);
    }
  }
else if((ch=='L')||(ch=='l')){
  if(root->left==NULL){
    root->left=New;
  }
  else{
    create(root->left,New);
  }
}
return root;
}

void preorder(struct node* root){
  if(root!=NULL){
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);

}

void inorder(struct node* root){
  if(root!=NULL){
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
  printf("%d ",root->data);
}

void postorder(struct node* root){
  if(root!=NULL){
  postorder(root->left);
  postorder(root->right);
  printf("%d",root->data);
}
