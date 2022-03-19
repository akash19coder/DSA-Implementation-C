#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*rear=NULL,*front=NULL;

//Global function declaration section
struct node* insert(int value);
struct node* delete(struct node *front,struct node *rear);
void display(struct node *front,struct node *rear);

//Main function starts here
void main(){
  struct node *head;
head=insert(10);
head=insert(20);
head=delete(front,rear);
display(front,rear);

}
struct node* insert(int value){
  struct node*new;
  new = (struct node*) malloc(sizeof(struct node));
  new->data = value;
  new->next=NULL;
  if(new==NULL){
    front=new;
    rear=new;
  }
  else{
    rear->next=new;
    rear=rear->next;
  }
  return front;
}

struct node* delete(struct node *front,struct node *rear){
  struct node *temp = front ;
  front=front->next;
  free(temp);
  return front;
}
void display(struct node *front,struct node*rear){
  for(;front!=rear->next;front=front->next){
    printf("%d",front->data);
  }
}
