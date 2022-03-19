#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Global Declaration section
struct node {
  struct node *prev;
  int data;
  struct node *next;
};

struct node* create();
void display(struct node *head);
void search(struct node *head,int value);

void main(){
  struct node *ptr =(struct node*)malloc(sizeof(struct node*));
  ptr=create();
  display(ptr);
  search(ptr,5);

}

//Create() function code
struct node* create(){
  struct node *head,*new,*temp;
  int value,flag=1;
  char ans ='y';



  do{
    new = (struct node*)malloc(sizeof(struct node));
    new->prev=NULL;
    new->next=NULL;

    printf("Enter the value\n");
    scanf("%d",&new->data);

    if(flag==1){
      head=new;
      temp=head;

    }
    else{
      head->prev=new;
      new->next=head;
      temp->next=new;
      new->prev=temp;
      temp=temp->next;
    }
    printf("Do you want to insert more nodes?(y/n)\n");
    ans=getch();
  }while(ans=='y'||ans=='Y');
  return head;
}

//Display() function goes here
void display(struct node *head){
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  temp=head;
  do{
    printf("%d\n",temp->data);
    temp=temp->next;

  }while(temp->next!=head);
getch();
}

void search(struct node *head,int value){
 int found=0;
 struct node* temp = head;


do{
  if(temp->data==value){
    found=1;
  }
  else{
    found=0;
  }
  temp=temp->next;
}while(temp->next!=head);

if(found==1){
  printf("The element exists\n");
}
else{
  printf("The element doesn't exists\n");
}

}
