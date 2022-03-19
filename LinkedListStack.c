#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
}*head=NULL;


void push(int value);
void display();
void pop();

void main(){
int choice,value;
do{
  printf("1.Push\n");
  printf("2.Pop\n");
  printf("3.Display\n");
  printf("4.Quit\n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  switch (choice) {
    case 1:
    printf("Enter the data you want to push\n");
    scanf("%d",&choice);
    push(value);
    break;

    case 2:
    pop();
    break;

    case 3:
    display();
    break;

    case 4:
    exit(1);
  }
}while(1);




}

void push(int value){

    struct node* new;
    new = (struct node*) malloc(sizeof(struct node));

    new->next=NULL;
    new->data=value;

    new->next=head;
    head=new;

}

void pop(){
  struct node *temp=head;
  head=head->next;
  free(temp);

}
void display(){
   struct node *temp=head;
   printf("The element in the stack are:\n");
   while(temp){
     printf("%d\n",temp->data);
     temp=temp->next;
   }
}i
